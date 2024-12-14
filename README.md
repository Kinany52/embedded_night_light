# Embedded Night Light

This repository contains a collection of variants of the Embedded Night Light, an embedded system project designed to control LEDs using various input methods. The project is built using an Arduino Uno, powered by the ATmega328P 8-bit microcontroller, and programmed in C++.

## Project Variants
1. **Night Light Remote Button Reader**: Reads and decodes IR remote signals.
2. **Night Light Potentiometer**: Adjusts LED brightness using a potentiometer.
3. **Night Light IR Remote Controller**: Combines IR remote functionality for brightness and power control.

Each variant explores a different interaction mechanism, demonstrating fundamental principles of embedded systems, such as analog signal processing, IR signal decoding, and microcontroller-driven control.

There is also a **Circuit Illustration** (circuit_illustration_image dir) that contains a diagram showing a simulated hardware setup for the project, for any of the variants above.

## Hardware Requirements
- Arduino Uno (ATmega328P)
- LEDs (x6)
- Potentiometer
- IR Receiver & IR Remote Controller
- Jumper Wires and Breadboard

## About the Microcontroller

The Arduino Uno uses the ATmega328P, an 8-bit AVR microcontroller with:

16 MHz Clock Speed
32 KB Flash Memory
6 PWM Outputs

## Architecture Overview

# Microcontroller: ATmega328P

The ATmega328P is an 8-bit AVR microcontroller used in the Arduino Uno. Its architecture and features make it an excellent platform for embedded systems projects.

# Key Features:

- Clock Speed: 16 MHz
- Word Size: 8-bit (processes data in 8-bit chunks)
- Memory:
-- Flash Memory: 32 KB (for program storage)
-- SRAM: 2 KB (for runtime variables)
-- EEPROM: 1 KB (for persistent data storage)
- Peripherals:
-- 6 PWM channels for LED brightness control.
-- Analog-to-Digital Converter (ADC) for reading analog inputs like the potentiometer.
-- Digital I/O pins with interrupt support for devices like IR receivers.
- Programming Language: C++ (via Arduino IDE)

This microcontroller provides a balance between simplicity and capability, making it suitable for small-scale embedded applications.

## Software

### Programming Language: C++
The Arduino sketches are written in C++, with support for Arduino-specific abstractions. The code leverages:

#### **Hardware Abstractions**
- `analogWrite()` for PWM control of LEDs.
- `analogRead()` for reading potentiometer input.
- Interrupts for handling IR signals.

#### **Libraries**
- **IRremote**: Decodes IR signals using hardware timers.

#### **Modular Functions**
- Brightness adjustments.
- Handling input from IR remotes and potentiometers.

---

## Hardware Requirements

### Components:
1. **Arduino Uno (ATmega328P)**:
   - Acts as the core microcontroller for the project.

2. **6 LEDs**:
   - Controlled via PWM to demonstrate brightness adjustments.

3. **IR Receiver**:
   - Receives signals from an IR remote to control LED states and brightness.

4. **Potentiometer**:
   - Analog input to dynamically adjust the brightness of LEDs.

5. **Jumper Wires and Breadboard**:
   - For prototyping and connecting components.

6. **Power Supply**:
   - USB power or external supply for the Arduino Uno.

---

## Variants

### **Variant 1: Night Light Remote Button Reader**
This variant is a foundational sketch to read and decode IR remote signals. It outputs the button press codes in hexadecimal format to the serial monitor.

#### **Features:**
- Reads IR remote signals using an IR receiver.
- Displays the signal codes for debugging or configuration purposes.

---

### **Variant 2: Night Light Potentiometer**
This variant uses a potentiometer to control the brightness of 6 LEDs.

#### **Features:**
- Reads the potentiometer's analog input (0–1023).
- Maps the input to PWM values (0–255) to adjust LED brightness.

---

### **Variant 3: Night Light IR Remote Controller**
This variant combines the IR receiver with LED control. The remote allows toggling LEDs on/off and adjusting brightness incrementally.

#### **Features:**
- Use of specific remote buttons for:
  - Power ON/OFF
  - Brightness UP
  - Brightness DOWN
- Combines signal decoding with real-time LED control.

---

### **Circuit Illustration Image**
Contains a TinkerCAD screenshot illustrating the complete circuit setup for the project.
