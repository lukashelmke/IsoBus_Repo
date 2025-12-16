# ISO 11783 NAME::Function Enum - Complete List

## Source
AgIsoStack++ Library - `can_NAME.hpp`
Located at: `.pio/libdeps/esp32doit-devkit-v1/AgIsoStack__/isobus/include/isobus/isobus/can_NAME.hpp`

## Overview
The NAME::Function enum defines ISO 11783 agricultural control function codes. Functions are defined in relation to industry group and device class according to ISO 11783-1 and www.isobus.net.

---

## Agricultural Equipment Functions (Industry Group 2-3)

### Industry Group 2: Agricultural and Forestry Equipment

#### Non-Specific System (Device Class 0) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `NonVirtualTerminalDisplay` | 128 | An operator display connected to the 11783 network that cannot perform as a Virtual Terminal |
| `OperatorControlsMachineSpecific` | 129 | Operator interface controls, either auxiliary control inputs or proprietary means |
| `TaskController` | 130 | Responsible for sending, receiving and logging of process data (ISO11783-10) |
| `ForeignObjectDetection` | 133 | Detection of undesirable objects in the product flow |
| `TractorECU` | 134 | Interface unit between tractor and implement bus (TECU) |
| `SequenceControlMaster` | 135 | Master controller in the Sequence Control System (ISO11783-14) |
| `ProductDosing` | 136 | Adds active ingredient to liquid carrier for field application (direct injection) |
| `ProductTreatment` | 137 | Mixes treatment to dry product applied to or harvested from fields |
| `DataLogger` | 139 | Data logger for non-task related data logging (ISO11783-10) |
| `DecisionSupport` | 140 | Control function for operator to configure operations optimally |
| `LightingController` | 141 | Controls electrical power to lights and reports status |
| `TIMServer` | 142 | Tractor Implement Management (TIM) Server |

#### Tractor (Device Class 1) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `AuxiliaryValveControl` | 129 | Control of tractor-mounted auxiliary valves |
| `RearHitchControl` | 130 | Control of the rear hitch of an agricultural tractor |
| `FrontHitchControl` | 131 | Control of the front hitch of an agricultural tractor |
| `CenterHitchControl` | 134 | Control of center hitch of an agricultural tractor |

#### Planters/Seeders (Device Class 4) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `DownPressure` | 137 | Control of ground contact pressure on product delivery unit |

#### Fertilizers (Device Class 5) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `ProductPressure` | 130 | Monitoring of pressure in the product delivery booms |

#### Harvesters (Device Class 7) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `TailingMonitor` | 128 | Measuring system to monitor unthreshed material quantity |
| `HeaderControl` | 129 | Control of header reel height, rotation, and material delivery rate |
| `ProductLossMonitor` | 130 | Measuring system to monitor grain being returned to soil |
| `HarvesterProductMoisture` | 131 | Measuring system to monitor moisture content of grain |

#### Forage (Device Class 9) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `TwineWrapperControl` | 128 | Control of twine wrapping around a bale before discharge |
| `ProductPackagingControl` | 129 | Control of packaging process for forage material |
| `ForageProductMoisture` | 131 | Measuring system to monitor moisture of forage content |

#### Transport/Trailer (Device Class 11) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `UnloadControl` | 136 | Control of trailer unloading process |

#### Sensor Systems (Device Class 17) - Industry Group 2
| Function Code | Value | Description |
|---|---|---|
| `GuidanceFeeler` | 128 | Mechanical function for determining row position in field |
| `CameraSystem` | 129 | Provides images or processed data for control operations |
| `CropScouting` | 130 | Measures vegetation parameters in standing crop |
| `MaterialPropertiesSensing` | 131 | Sensing system to detect material properties (density, particle size, color, constituents) |
| `InertialMeasurementUnit` | 132 | Sensor unit providing inertial measurements |
| `ProductMass` | 135 | Measuring function to monitor product mass |
| `VibrationKnock` | 136 | Measuring function to determine vibration/knock behavior |
| `WeatherInstruments` | 137 | Weather Instruments function code per ISO11783 |
| `SoilScouting` | 138 | Soil Sensor measuring different soil physical parameters |

---

### Industry Group 3: Construction Equipment

#### Non-Specific System (Device Class 0) - Industry Group 3
| Function Code | Value | Description |
|---|---|---|
| `ConstructionSupplementalEngineControlSensing` | 128 | Supplemental Engine Control Sensing |
| `LaserReceiver` | 129 | Laser Receiver |
| `LandLevelingSystemOperatorInterface` | 130 | Component for controlling Land Leveling System |
| `LandLevelingElectricMast` | 131 | Land Leveling Electric Mast |
| `SingleLandLevelingSystemSupervisor` | 132 | Single Land Leveling System Supervisor |
| `LandLevelingSystemDisplay` | 133 | Land Leveling System Display |
| `LaserTracer` | 134 | Laser Tracer |
| `LoaderControl` | 135 | Loader control unit |
| `ConstructionEquipmentSlopeSensor` | 136 | Measures slope along an axis |
| `LiftArmControl` | 137 | Controller for lift arms and tilt functions |
| `SupplementalSensorProcessingUnits` | 138 | I/O module for data collection |
| `HydraulicSystemPlanner` | 139 | Coordinates functions of valve controllers |
| `HydraulicValveController` | 140 | Controls flow of oil to specific cylinder |
| `JoystickControl` | 141 | Joystick Control |
| `RotationSensor` | 142 | Measures rotational angle around axis |
| `SonicSensor` | 143 | Measures distance via ultrasonic pulse/echo |
| `SurveyTotalStationTarget` | 144 | Survey total station target on construction machine |
| `HeadingSensor` | 145 | Measures vehicle azimuth |
| `AlarmDevice` | 146 | Provides audible and/or visual alarm |

#### Skid Steer Loader (Device Class 1) - Industry Group 3
| Function Code | Value | Description |
|---|---|---|
| `SkidSteerMainController` | 128 | Main controller for skid steer machine |

#### Crawler (Device Class 4) - Industry Group 3
| Function Code | Value | Description |
|---|---|---|
| `BladeController` | 128 | Controller for blade height |

#### Grader (Device Class 8) - Industry Group 3
| Function Code | Value | Description |
|---|---|---|
| `HFWDController` | 128 | Hydraulic front wheel drive controller |

---

## Common Functions (All Industry Groups)

These functions are available across all industry groups and are defined for general-purpose use:

| Function Code | Value | Description |
|---|---|---|
| `Engine` | 0 | Mechanical power source of the machine |
| `AuxiliaryPowerUnit` | 1 | Power source for operating systems without prime drive engine |
| `ElectricPropulsionControl` | 2 | Control system for electrically powered drive |
| `Transmission` | 3 | Mechanical system for altering speed vs. torque |
| `BatteryPackMonitor` | 4 | Monitors battery pack condition |
| `ShiftControl` | 5 | Determines and transmits desired gear |
| `PowerTakeOffRearOrPrimary` | 6 | Controls mechanical power from prime engine |
| `SteeringAxle` | 7 | Adjusts attack angle of steering axle |
| `DrivingAxle` | 8 | Adjusts attack angle of driving axle |
| `SystemControlBrakes` | 9 | Electronic service braking system control |
| `SteerAxleControlBrakes` | 10 | Service brake control on steered axle |
| `DriveAxleControlBrakes` | 11 | Service brake control on drive axle |
| `EngineRetarder` | 12 | Engine retarder control |
| `DrivelineRetarder` | 13 | Driveline retarder control |
| `CruiseControl` | 14 | Speed maintenance control |
| `FuelSystem` | 15 | Fuel flow control |
| `SteeringControl` | 16 | Steer-by-wire control |
| `SteerAxleSuspensionControl` | 17 | Steered axle suspension control |
| `DriveAxleSuspensionControl` | 18 | Driven axle suspension control |
| `InstrumentCluster` | 19 | Gauge display for vehicle |
| `TripRecorder` | 20 | System for accumulating travel data |
| `CabClimateControl` | 21 | Cab climate control system |
| `AerodynamicControl` | 22 | Drag modification via body panels |
| `VehicleNavigation` | 23 | Vehicle position/navigation system |
| `VehicleSecurity` | 24 | Security/authentication system |
| `NetworkInterconnectUnit` | 25 | Connects different network segments |
| `BodyControl` | 26 | Body suspension control independent from axle |
| `PowerTakeOffFrontOrSecondary` | 27 | Secondary mechanical power from engine |
| `OffVehicleGateway` | 28 | Off-vehicle system connection |
| `VirtualTerminal` | 29 | General-purpose intelligent display (ISO 11783-6) |
| `ManagementComputerOne` | 30 | Manages vehicle systems (powertrain) |
| `PropulsionBatteryCharger` | 31 | Propulsion battery charging unit |
| `HeadwayControl` | 32 | Collision avoidance/warning/speed control |
| `SystemMonitor` | 33 | Generic system monitor |
| `HydraulicPumpControl` | 34 | Hydraulic power pump controller |
| `SystemControlSuspension` | 35 | Overall suspension coordination |
| `SystemControlPneumatic` | 36 | Pneumatics coordination |
| `CabController` | 37 | Cab-located function controller |
| `TirePressureControl` | 38 | Centralized tire inflation control |
| `IgnitionControl` | 39 | Engine ignition control |
| `SeatControl` | 40 | Cab seat control system |
| `OperatorControlsLighting` | 41 | Operator lighting controls |
| `WaterPumpControl` | 42 | Water pump controller |
| `TransmissionDisplay` | 43 | Transmission information display |
| `ExhaustEmissionControl` | 44 | Emissions control |
| `VehicleDynamicStabilityControl` | 45 | Stability control |
| `OilSystemMonitor` | 46 | Oil level/life/temperature monitoring |
| `InformationSystemControl` | 47 | Vehicle information management |
| `RampControl` | 48 | Loading/unloading ramp control |
| `ClutchConverterControl` | 49 | Torque converter or engine-transmission connection |
| `AuxiliaryHeater` | 50 | Primary heat from engine coolant |
| `ForwardLookingCollisionWarningSystem` | 51 | Collision detection and warning |
| `ChassisControl` | 52 | Chassis component control |
| `AlternatorElectricalChargingSystem` | 53 | Primary on-board charging controller |
| `CommunicationsCellular` | 54 | Cellular radio communications unit |
| `CommunicationsSatellite` | 55 | Satellite communications unit |
| `CommunicationsRadio` | 56 | Terrestrial p2p radio communications |
| `OperatorControlsSteeringColumn` | 57 | Steering column control input gathering |
| `FanDriveControl` | 58 | Main cooling fan operation control |
| `Starter` | 59 | Engine starter motor system |
| `CabDisplayCab` | 60 | Elaborate in-cab display (non-VT) |
| `FileServerOrPrinter` | 61 | Printing or file storage unit |
| `OnboardDiagnosticUnit` | 62 | Permanently mounted diagnostic tool |
| `EngineValveController` | 63 | Engine intake/exhaust valve control |
| `EnduranceBraking` | 64 | Friction-free engine braking |
| `GasFlowMeasurement` | 65 | Gas flow rate measurement |
| `IOController` | 66 | External input/output channel control |
| `ElectricalSystemController` | 67 | Load centers, fuse boxes, power distribution |
| `AftertreatmentSystemGasMeasurement` | 68 | Aftertreatment system gas measurement |
| `EngineEmissionAftertreatmentSystem` | 69 | Engine emission aftertreatment |
| `AuxiliaryRegenerationDevice` | 70 | Auxiliary regeneration device |
| `TransferCaseControl` | 71 | 2/4 wheel drive selection |
| `CoolantValveController` | 72 | Coolant flow control |
| `RolloverDetectionControl` | 73 | Vehicle rollover detection |
| `LubricationSystem` | 74 | System lubricant pumping |
| `SupplementalFan` | 75 | Auxiliary cooling fan |
| `TemperatureSensor` | 76 | Temperature measurement device |
| `FuelPropertiesSensor` | 77 | Fuel properties measurement |
| `FireSuppressionSystem` | 78 | Fire suppression system |
| `PowerSystemsManager` | 79 | Power output management controller |
| `ElectricPowertrain` | 80 | Electric drive system controller |
| `HydraulicPowertrain` | 81 | Hydraulic drive system controller |
| `FileServer` | 82 | Permanent file storage unit |
| `Printer` | 83 | Permanent printing unit |
| `StartAidDevice` | 84 | Engine starting assistance device |
| `EngineInjectionControlModule` | 85 | Fuel injection control |
| `EVCommunicationController` | 86 | Electric vehicle supply connection manager |
| `DriverImpairmentDevice` | 87 | Alcohol interlock or similar device |
| `ElectricPowerConverter` | 88 | AC/DC power inverter or converter |
| `SupplyEquipmentCommunicationController` | 89 | EVSE charging station communication |
| `VehicleAdapterCommunicationController` | 90 | EV adapter communication controller |
| `RateControl` | 128 | Product application rate control |
| `SectionOnOffControl` | 129 | Individual section on/off control |
| `PositionControl` | 131 | Multi-axis position control |
| `MachineControl` | 132 | Output control including adjustment functions |
| `ProductFlow` | 133 | Product flow monitoring |
| `ProductLevel` | 134 | Product level monitoring |
| `DepthOrHeightControl` | 135 | Tool depth/boom height control |
| `FrameControl` | 136 | Frame folding/unfolding control |
| `MaxFunctionCode` | 255 | Maximum allocated function code |

---

## Usage Example in Code

```cpp
#include "can_NAME.hpp"

using namespace isobus;

// Create a NAME with specific function
NAME myName;
myName.set_function_code(NAME::Function::RateControl);  // ISO 11783 rate control
myName.set_device_class(NAME::DeviceClass::Fertilizer);
myName.set_industry_group(NAME::IndustryGroup::AgriculturalAndForestryEquipment);
```

---

## Reference
- **Standard**: ISO 11783-1 (Agricultural and forestry machines - Serial control and communications data network)
- **Additional Information**: www.isobus.net
- **Library**: AgIsoStack++ (Open Agriculture)
