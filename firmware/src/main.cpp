#include "isobus/hardware_integration/can_hardware_interface.hpp"
#include "isobus/hardware_integration/twai_plugin.hpp"

#include "isobus/isobus/can_network_manager.hpp"
#include "isobus/isobus/can_partnered_control_function.hpp"
#include "isobus/isobus/isobus_virtual_terminal_client.hpp"
#include "isobus/isobus/isobus_task_controller_server.hpp"
#include "isobus/isobus/can_stack_logger.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"


#include <cstdint>
#include <cstdio>
#include <memory>
#include <vector>


extern "C" const uint8_t object_pool_start[] asm("_binary_ESP_Controler_iop_start");
extern "C" const uint8_t object_pool_end[]   asm("_binary_ESP_Controler_iop_end");


class SimpleLogger : public isobus::CANStackLogger
{
public:
	void sink_CAN_stack_log(LoggingLevel level, const std::string &text) override
	{
		printf("[AgIsoStack %d] %s\n", static_cast<int>(level), text.c_str());
	}
};

static SimpleLogger g_logger;


struct Relay { uint16_t id; gpio_num_t gpio; };
static Relay relays[] = { {6000, GPIO_NUM_5}, {6001, GPIO_NUM_18}, {6002, GPIO_NUM_19}, {6003, GPIO_NUM_23} };

static void init_relays()
{
	for (auto &r : relays)
	{
		gpio_config_t cfg = {};
		cfg.intr_type = GPIO_INTR_DISABLE;
		cfg.mode = GPIO_MODE_OUTPUT;
		cfg.pin_bit_mask = (1ULL << r.gpio);
		gpio_config(&cfg);
		gpio_set_level(r.gpio, 0);
		printf("Relay on GPIO %d configured\n", r.gpio);
	}
}

static void set_relay(uint16_t id, bool on)
{
	for (auto &r : relays)
	{
		if (r.id == id)
		{
			gpio_set_level(r.gpio, on ? 1 : 0);
			printf("Relay %u -> %s\n", id, on ? "ON" : "OFF");
			return;
		}
	}
}

static std::shared_ptr<isobus::VirtualTerminalClient> g_vt;

static void button_cb(const isobus::VirtualTerminalClient::VTKeyEvent &ev)
{
	
	if (ev.keyEvent == isobus::VirtualTerminalClient::KeyActivationCode::ButtonPressedOrLatched)
		set_relay(ev.objectID, true);
	else if (ev.keyEvent == isobus::VirtualTerminalClient::KeyActivationCode::ButtonUnlatchedOrReleased)
		set_relay(ev.objectID, false);
}

extern "C" void app_main()
{
	isobus::CANStackLogger::set_can_stack_logger_sink(&g_logger);
	isobus::CANStackLogger::set_log_level(isobus::CANStackLogger::LoggingLevel::Info);


	twai_general_config_t gcfg = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_21, GPIO_NUM_22, TWAI_MODE_NORMAL);
	twai_timing_config_t tcfg = TWAI_TIMING_CONFIG_250KBITS();
	twai_filter_config_t fcfg = TWAI_FILTER_CONFIG_ACCEPT_ALL();
	auto driver = std::make_shared<isobus::TWAIPlugin>(&gcfg, &tcfg, &fcfg);
	isobus::CANHardwareInterface::set_number_of_can_channels(1);
	isobus::CANHardwareInterface::assign_can_channel_frame_handler(0, driver);
	isobus::CANHardwareInterface::set_periodic_update_interval(10);
	if ((!isobus::CANHardwareInterface::start()) || (!driver->get_is_valid()))
	{
		printf("CAN start failed\n");
		while (true) vTaskDelay(pdMS_TO_TICKS(1000));
	}

	vTaskDelay(pdMS_TO_TICKS(250));

	
	isobus::NAME myNAME(0);
	myNAME.set_arbitrary_address_capable(true);
	myNAME.set_industry_group(2);  
	myNAME.set_function_code(static_cast<std::uint8_t>(isobus::NAME::Function::PositionControl));
	myNAME.set_identity_number(2);
	auto internal = isobus::CANNetworkManager::CANNetwork.create_internal_control_function(myNAME, 0);

	std::vector<isobus::NAMEFilter> vtFilters = { isobus::NAMEFilter(isobus::NAME::NAMEParameters::FunctionCode, static_cast<std::uint8_t>(isobus::NAME::Function::VirtualTerminal)) };
	auto partnerVT = isobus::CANNetworkManager::CANNetwork.create_partnered_control_function(0, vtFilters);


	auto vt = std::make_shared<isobus::VirtualTerminalClient>(partnerVT, internal);
	g_vt = vt;  

	
	const uint8_t *poolStart = object_pool_start;
	const uint8_t *poolEnd   = object_pool_end;
	std::size_t poolSize = static_cast<std::size_t>(poolEnd - poolStart);
	vt->set_object_pool(0, poolStart, static_cast<std::uint32_t>(poolSize), "VTPOOL");
	vt->initialize(true);

	init_relays();
	vt->get_vt_button_event_dispatcher().add_listener(button_cb);

	bool prevConnected = false;
	while (true)
	{
		bool connected = vt->get_is_connected();
		if (connected && !prevConnected)
		{
			vt->set_object_pool(0, poolStart, static_cast<std::uint32_t>(poolSize), "VTPOOL");
			printf("VT connected, pool assigned\n");
		}
		prevConnected = connected;
		vTaskDelay(pdMS_TO_TICKS(50));
	}
}
