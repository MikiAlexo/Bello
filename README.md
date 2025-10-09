# Bello
Automatic school bell system with configurable schedules and a simplified variant.
Built with microcontrollers (Arduino / ESP32) using PlatformIO.

This is what the finished prototype looks like:- https://youtu.be/g8njpu9FO_w?si=gBSwjOJio-1_8WDL

## Features
- Automatic ringing based on configurable schedules.
- Real-time clock (RTC) support for accurate timing.
- Persistent storage of schedules (survives power loss).

## Getting Started
### Bello mini
#### Requirements
- PlatformIO
- Arduino Uno
- RTC module (DS3232)
- Relay: 220 V common / 5 V control
- OLED SSD1306(0,96')

### Bello
#### Requirements
- PlatformIO
- Arduino Uno
- RTC module (DS3232)
- Relay: 220 V common / 5 V control
- SH110X OLED(1,3')
- Push buttons x6
- Passive Buzzer
- 9v battery
### Bello-IOT
#### Requirements
- PlatformIO
- ESP32 wroom dev board(Generic)
- RTC module (DS3232)
- Relay: 220 V common / 5 V control
- phone/pc to access device settings

## PCB Design for Bello
 The device has two PCB, one for the main circuits and the other for input buttons.
 I know an image isn't the best way to share a PCB design so just take mine as a reference when making your's.

### Main board

<img width="818" height="542" alt="image" src="https://github.com/user-attachments/assets/4b1f7d41-52da-45fe-8dce-e687dce59458" />



