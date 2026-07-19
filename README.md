# Smart Trash Collection Rover

An IoT-based autonomous waste collection system built using dual ESP32 microcontrollers, LoRa communication, and Blynk IoT for real-time monitoring. The system is designed to automate waste collection by monitoring dustbin fill levels, navigating autonomously, and providing live operational status through a cloud dashboard.

---

# Project Overview

The Smart Trash Collection Rover is an intelligent robotic waste management system that reduces manual intervention in waste collection. The system consists of two ESP32 development boards working together through LoRa communication.

The **Transmitter ESP32** continuously monitors the fill level of two dustbins using ultrasonic sensors and detects waste presence using IR sensors. The collected data is transmitted wirelessly to the **Receiver ESP32**.

The **Receiver ESP32** performs autonomous navigation using line-following sensors, controls the robotic collection mechanism, processes incoming sensor data, and uploads the system status to the Blynk IoT Cloud via Wi-Fi for remote monitoring.

The project demonstrates an edge-computing approach where the majority of processing and decision-making occurs locally on the ESP32 devices while the cloud is used only for visualization and monitoring.

---

# Team Members

| Name | Email |
|------|-------|
| Manojkumar | manojkumar.tech.in@gmail.com |
| Jerin Ansfrid | cjerinansfrid@gmail.com |
| Vijay | vijaymahesh791@gmail.com |
| Ilayabharathi | ilayabharathik73@gmail.com|
| Lakshmidevi | lakshmidevi.k2006@gmail.com|

---

# Key Features

- Autonomous waste collection rover
- Dual ESP32 architecture
- LoRa-based wireless communication
- Real-time Blynk IoT monitoring
- Dual dustbin level monitoring
- Line-following navigation
- Robotic arm for waste collection
- LCD status display
- Local edge processing
- Remote monitoring over Wi-Fi

---

# System Architecture

```
               Ultrasonic Sensors
                     │
                IR Sensors
                     │
          ESP32 Transmitter
                     │
             LoRa Communication
                     │
          ESP32 Receiver
         ┌────────────┴────────────┐
         │                         │
 Motor Control             Wi-Fi Connection
         │                         │
 Robotic Rover             Blynk IoT Cloud
                                   │
                            Mobile Dashboard
```

---

# Hardware Components

- ESP32 Dev Module ×2
- LoRa Modules ×2
- HC-SR04 Ultrasonic Sensors ×2
- IR Sensors
- L298N Motor Driver
- DC Motors
- Robotic Arm Mechanism
- I2C LCD Display
- Battery Pack
- Chassis
- Connecting Wires

---

# Software Stack

- Arduino IDE
- ESP32 Board Package
- Blynk IoT Platform
- Git & GitHub

---

# Arduino Libraries

Install the following libraries before compiling the project.

- WiFi
- Blynk
- BlynkSimpleEsp32
- LCD_I2C
- Wire

---

# Repository Structure

```
Smart-Trash-Collection-Rover
│
├── BLINK/
│   └── Blynk Configuration
│
├── ESP32_TRANSMITTER/
│   └── transmitter.ino
│
├── MOTOR/
│   └── receiver.ino
│
├── SMART_ROVER/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── WEBCAM_TRAIN/
│
├── images/
│
├── LICENSE
│
└── README.md
```

---

# Installation Guide

## Step 1

Clone the repository.

```bash
git clone https://github.com/<YOUR_GITHUB_USERNAME>/Smart-Trash-Collection-Rover.git
```

---

## Step 2

Open the project using Arduino IDE.

---

## Step 3

Install the ESP32 Board Package.

```
Arduino IDE
→ File
→ Preferences
→ Additional Board Manager URLs
→ https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Then:

```
Tools
→ Board
→ Boards Manager
→ Search "ESP32"
→ Install "ESP32 by Espressif Systems"
```

---

## Step 4

Install Required Libraries

```
Sketch
→ Include Library
→ Manage Libraries
```

Install:

- WiFi
- Blynk
- LCD_I2C

---

## Step 5

Open:

```
ESP32_TRANSMITTER/transmitter.ino
```

Configure:

- Wi-Fi SSID
- Wi-Fi Password

Upload the code to the transmitter ESP32.

---

## Step 6

Open:

```
MOTOR/receiver.ino
```

Configure:

- Wi-Fi SSID
- Wi-Fi Password
- Blynk Template ID
- Blynk Authentication Token

Upload the code to the receiver ESP32.

---

## Step 7

Power both ESP32 boards.

Ensure that:

- LoRa modules are connected.
- Both ESP32 devices are powered.
- Receiver ESP32 is connected to Wi-Fi.

---

# Usage Instructions

1. Power ON both ESP32 boards.
2. Connect the receiver ESP32 to the configured Wi-Fi network.
3. Launch the Blynk IoT application.
4. Place waste inside either dustbin.
5. The transmitter measures the dustbin fill level.
6. Sensor data is transmitted using LoRa.
7. The receiver receives the sensor values.
8. The rover navigates autonomously using line-following sensors.
9. The robotic arm collects the waste.
10. Real-time sensor values and rover status are displayed on the Blynk dashboard.

---

# Edge Computing

The application follows a hybrid Edge-Cloud architecture.

## Edge Processing

- Ultrasonic sensing
- IR sensing
- Line following
- Motor control
- Robotic arm control
- LoRa communication
- Autonomous decision making

## Cloud Services

- Blynk IoT Dashboard
- Remote Monitoring

Most computation is performed locally on the ESP32 devices.

---

# Testing

The following tests were performed.

### Sensor Test

- Ultrasonic distance measurement
- IR sensor detection
- Dustbin percentage calculation

### Communication Test

- LoRa packet transmission
- LoRa packet reception

### Rover Test

- Forward movement
- Reverse movement
- Left turn
- Right turn
- Stop
- Waste collection mechanism

### Dashboard Test

- Dustbin level updates
- Rover status updates
- LoRa status updates
- Battery status updates

---

# References

- Arduino Documentation
- ESP32 Documentation
- Blynk IoT Documentation
- LoRa Module Documentation
- GitHub Documentation

---

# Acknowledgements

We thank our faculty mentors and institution for their continuous guidance and support throughout the development of this project.

This repository has been developed as part of the **Smart Trash Collection Rover** project to demonstrate autonomous waste collection using edge computing, wireless communication, and IoT technologies.
