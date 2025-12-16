<p align="right">
  <img src="VT_ObjectPool/images/g452ffdf6.png" width="70">
</p>


# ISOBUS VT Relais Controller  
**ESP32 + AgIsoStack + IsoDesigner**


Dieses Projekt implementiert ein eigenes ISOBUS-Gerät auf Basis eines ESP32,
das sich an ein ISOBUS Virtual Terminal (VT) anmeldet und über Touch-Buttons
am Terminal vier externe Relais schaltet.

Der ESP32 fungiert dabei als **Virtual Terminal Client** und nutzt die
Open-Source-Bibliothek **AgIsoStack** zur ISOBUS-Kommunikation.
Der Virtual-Terminal-Object-Pool wurde mit dem **IsoDesigner** erstellt.

---

## 📌 Projektübersicht

Ziel dieses Projekts ist es, eine einfache und robuste ISOBUS-Bedieneinheit
zu realisieren, mit der digitale Ausgänge (Relais) direkt über ein vorhandenes
ISOBUS-Terminal geschaltet werden können.

Typische Anwendungsfälle:
- Schalten und steuern von elektrischen Komponenten 
- Prototyping von ISOBUS-Funktionen
- Lernen und Verstehen der ISOBUS-VT-Kommunikation

---

## Systemarchitektur

### Hardware-Komponenten
- ISOBUS Terminal 
- ESP32 Mikrocontroller
- [CanBus](https://www.amazon.de/dp/B0CPJ6HW9K?ref=ppx_yo2ov_dt_b_fed_asin_title) Modul SN65HVD-230
- 4-Kanal Relaismodul
- D-SUB 9Pin Stecker und Buchsen

### Software-Komponenten
- [AgIsoStack](https://agisostack-plus-plus.readthedocs.io/en/latest/index.html) (ISOBUS Stack) 
- PlatformIO / VS Code
- [IsoDesigner](https://www.bucherautomation.com/iso-designer/sw10133) (VT Object Pool Design)




---
## ESP32 Relais- und CAN-Modul


#### Schaltplan:

<p align="center">
  <img src="hardware/circuits/ESP32_Isobus_Client_4ChRelay.png" width="700">
</p>

#### CAD: 

<p align="center">
  <img src="hardware/CAD/ESP32_IsoBus_Relais.png" width="700">
</p>

*Abbildung: ESP32 mit Relais und CAN Modul*

---

## ISOBUS Verteilerbox

Die Verteilerbox übernimmt folgende Aufgaben:
- Versorgung des ISOBUS Terminals mit Spannung
- Durchschleifen des CAN-Bus
- Abgriff von CAN High und CAN Low
- optionales zuschalten eines Abschlusswiderstands
- Verbindung zum ESP32 über DSUB-Steckverbinder

### Schaltplan: ISOBUS Verteilerbox

<p align="center">
  <img src="hardware/circuits/IsoBus_Verteiler.png" width="700">
</p>

entsprechende CAD dateien sind in diesem Repo ebenfalls enthalten.

<p align="center">
  <img src="hardware/CAD/IsoBus_Verteiler.PNG" width="700">
</p>

*Abbildung: ISOBUS Strom- und CAN-Verteilerbox*

---
## 🖥️ Virtual Terminal Object Pool

### Was ist ein VT Object Pool?

Ein **Virtual Terminal Object Pool** beschreibt die komplette grafische
Benutzeroberfläche eines ISOBUS-Gerätes:
- Masken (Screens)
- Buttons
- Texte
- Eingabeelemente
- Macros
- Objekt-IDs und Eigenschaften

Der Object Pool wird von dem ESP an das Terminal übertragen.
Das Terminal rendert anschließend die Oberfläche und sendet
Benutzeraktionen (z. B. Button-Drücke) über den Can Bus.

### Erstellung des Object Pools mit dem IsoDesigner


Der Object Pool dieses Projekts wurde mit dem [IsoDesigner](https://www.bucherautomation.com/iso-designer/sw10133) erstellt.


> ### Was ist der IsoDesigner?
> Der **IsoDesigner** ist ein grafisches Entwicklungswerkzeug zur Erstellung
> von ISOBUS Virtual-Terminal-Oberflächen gemäß ISO 11783.
> Er ermöglicht das visuelle Erstellen von Masken und Bedienelementen
> ohne manuelles Schreiben von Object-Pool-Strukturen.

Ein guter Einstieg in die Software lässt sich auch über entsprechende [Tutorials](https://youtu.be/10cyF99BziY?si=aGUhjTgAsRmfgrT0)


### Vorgehensweise (vereinfacht)

1. Neues VT-Projekt im IsoDesigner erstellen
2. Virtuelles Terminal mit entsprechendem VT-Level als Zielgerät auswählen
3. Datenmaske anlegen
4. Vier Buttons platzieren
5. Jedem Button eine eindeutige **Object-ID** zuweisen
6. Button-Typ festlegen (Momenttaster oder rastend)
7. Projekt kompilieren
8. Export der `.iop` Datei (Object Pool)

Die erzeugte `.iop` Datei wird anschließend:
- ins ESP32-Firmwareprojekt eingebunden (`firmware/object_pool/ESP_Controler.iop`)
- beim Start des ESP an das Virtual Terminal übertragen


## Firmware (ESP32)

Die Firmware wurde unter verwendung von  **VS Code** und **PlatformIO** geschrieben und auf dem ESP geflasht. Dabei wurde sich sehr eng an das [Tutorial](https://agisostack-plus-plus.readthedocs.io/en/latest/Tutorials/ESP32%20PlatformIO.html) von AgIsoStack gehalten.

### Hauptfunktionen

- CAN-Kommunikation über ESP32 TWAI Controller
- ISOBUS Address Claiming
- Virtual Terminal Client
- Übertragung des Object Pools
- Empfang und Auswertung von VT Key Events
- Ansteuerung der GPIO-Ausgänge

### ISOBUS-Einstellungen

- Baudrate: **250 kbit/s**
- CAN Filter: Accept All
- Unterstützt Arbitrary Address Claiming



## Technischer Ablauf

1. ESP32 startet
2. Initialisierung der GPIOs (Relais AUS)
3. Initialisierung des CAN-Controllers
4. ISOBUS Address Claiming
5. Suche nach einem Virtual Terminal
6. Übertragung des VT Object Pools
7. Benutzerinteraktion am Terminal
8. Empfang von Button-Events
9. Schalten der entsprechenden Relais


### Button- & Relais-Zuordnung

Die Object-IDs der VT-Buttons sind in dem Projekt mit folgenden GPIO's des ESP verknüpft:

| VT Object ID | Funktion     | ESP32 GPIO | Relais |
|-------------|--------------|-----------|--------|
| 6000        | Relais 1     | GPIO 5    | Ch1    |
| 6001        | Relais 2     | GPIO 18   | Ch2    |
| 6002        | Relais 3     | GPIO 19   | Ch3    |
| 6003        | Relais 4     | GPIO 23   | Ch4    |

### VT Button Eventhandling (AgIsoStack)
Das Laden/Übertragen des VT Object Pools ist nur die eine Seite.  
Damit aus einem Button auf dem Terminal tatsächlich eine Aktion im Gerät wird,
muss der ESP32 die **VT Key Events** auswerten, die das Terminal über ISOBUS sendet.

AgIsoStack stellt dafür im `VirtualTerminalClient` einen Event-Dispatcher bereit,
über den man Callback-Funktionen registrieren kann.


### Grundprinzip

1. Der VT rendert den Object Pool (Maske, Buttons, etc.)
2. Der Benutzer drückt oder löst einen Button
3. Der VT sendet ein **Key Event** über den ISOBUS CAN-Bus
4. AgIsoStack dekodiert dieses Event und triggert deinen Callback
5. Dein Callback wertet die **Object-ID** und den **KeyActivationCode** aus
6. Daraus leitet man die gewünschte Aktion ab (hier: Relais schalten)



## Build & Flash

1. VS Code installieren
2. PlatformIO Extension installieren
3. Projektordner `firmware` öffnen
4. ESP32 per USB anschließen
5. PThreads und FreeRTOS anpassen
5. Build & Upload ausführen

---

## ⚠️ Einschränkungen

- Keine Rückmeldung des Relaisstatus im VT
- Kein Task Controller Support
- Keine Fehlerdiagnoseanzeige

---

## 🧠 Mögliche Erweiterungen

- Anzeige des Relaisstatus im VT
- Task Controller Integration
- Failsafe-Logik bei CAN-Ausfall
- Speicherung des letzten Zustands im Flash