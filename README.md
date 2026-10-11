# ESP32 Autonomous Sumobot

This repository contains the embedded C++ logic to control gearmotors and read ultrasonic sensors for a competitive sumobot.

## Hardware Components
- 1x ESP32 Microcontroller
- 2x DC Gearmotors
- 1x L298N Motor Driver
- **1x Ultrasonic Sensor (HC-SR04)**

## Pinout Connections

| ESP32 Pin | Component       | Connection |
| --------- | --------------- | ---------- |
| GPIO 5    | L298N Driver    | IN1        |
| GPIO 18   | HC-SR04 Sensor  | TRIG       |