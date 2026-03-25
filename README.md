# Automatic Toll Gate Barrier System (ESP32)

This project is an ESP32-based **automatic toll gate barrier system** that uses an **ultrasonic sensor** to detect approaching vehicles and automatically controls a **servo motor barrier**.

The system opens the barrier when a vehicle is detected within a set distance and closes it after a short delay.

---

## Project Overview

The system works by:

- continuously measuring distance using an ultrasonic sensor  
- detecting when a vehicle approaches  
- opening a barrier using a servo motor  
- automatically closing the barrier after a delay  

It provides a simple and cost-effective solution for:
- toll gates  
- parking entrances  
- automated access control  

---

## Features

### 🚗 Vehicle Detection
- Uses ultrasonic sensor (HC-SR04 or similar)  
- Measures distance in real-time  
- Detects objects within a defined threshold  

---

### 🚧 Automatic Barrier Control
- Opens barrier when vehicle is near  
- Closes barrier after a delay  
- Uses servo motor for smooth movement  

---

### 📺 LCD Display
- 16x2 I2C LCD  
- Displays:
  - distance from object  
  - barrier status (OPEN/CLOSE)  

---

### ⚙️ Adjustable Distance Threshold
- Default trigger distance: **20 cm**  
- Can be modified in code  

---

### 🔧 Manual Testing Mode
- Allows manual control via Serial:
  - `"0"` → Open barrier  
  - `"1"` → Close barrier  

---

## System Workflow

### 1. Idle State
- Barrier is CLOSED  
- System continuously reads distance  

---

### 2. Vehicle Detection
- If distance ≤ threshold:
  - vehicle detected  

---

### 3. Barrier Opens
- Servo rotates to OPEN position  
- LCD displays: BARRIER OPEN

---

### 4. Delay
- System waits for a few seconds  

---

### 5. Barrier Closes
- Servo returns to CLOSED position  
- LCD displays: BARRIER CLOSE

---

## Pin Configuration (ESP32)

| Component          | ESP32 Pin |
|-------------------|----------|
| Ultrasonic TRIG   | 18       |
| Ultrasonic ECHO   | 5        |
| Servo Motor       | 17       |
| LCD (SDA)         | 21       |
| LCD (SCL)         | 22       |

---

## Wiring Connections

### 📏 Ultrasonic Sensor (HC-SR04)
- TRIG → GPIO 18  
- ECHO → GPIO 5  
- VCC → 5V  
- GND → GND  

---

### ⚙️ Servo Motor
- Signal → GPIO 17  
- VCC → 5V (external recommended)  
- GND → GND  

---

### 📺 LCD (I2C)
- SDA → GPIO 21  
- SCL → GPIO 22  
- VCC → 5V  
- GND → GND  

---

## Hardware Components

- ESP32  
- Ultrasonic Sensor (HC-SR04)  
- Servo Motor  
- 16x2 LCD (I2C)  
- Jumper Wires  
- Power Supply  

---

## Key Parameters

| Parameter           | Value |
|--------------------|------|
| Open Angle         | 90°  |
| Close Angle        | 0°   |
| Trigger Distance   | 20 cm |
| Open Delay         | 3 seconds |

---

## Notes

- Use external power for servo to avoid ESP32 reset  
- Ensure proper grounding between all components  
- Adjust distance threshold depending on application  
- LCD address may vary (commonly 0x27)  

---

## Limitations

- No vehicle identification (RFID, etc.)  
- No multi-lane support  
- Distance-based only (no AI detection)  
- Fixed delay timing  

---

## Summary

This project demonstrates a simple **automated barrier system** that combines:

- ultrasonic sensing  
- servo motor control  
- real-time display  

It is suitable for:

- toll gate systems  
- parking automation  
- access control prototypes  
- embedded system projects  
