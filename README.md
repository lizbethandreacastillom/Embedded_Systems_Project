
---
# Secure Access Management System

**Embedded Systems Project**

---

##  Project Overview

This project consists of the design and implementation of a secure access control system using an ESP32 DevKit V1 operating as a Micro Web Server (MWS).

The system allows users to scan a QR code to access a locally hosted web interface. After entering a PIN, the ESP32 validates the credentials internally and activates a physical actuator (relay or servo motor) to simulate door unlocking.

The project integrates embedded systems programming, wireless networking, and cybersecurity principles into a single autonomous device.

---

## Objective

To design and implement a secure embedded access control system that:

* Hosts its own web server
* Authenticates users via PIN
* Controls a physical actuator
* Implements brute-force protection
* Operates independently without cloud services

---

##  System Architecture

The system is divided into three main layers:

1. **Hardware Layer** – ESP32, relay module, servo motor, status LEDs
2. **Network Layer** – Wi-Fi Access Point (AP mode) with WPA2 encryption
3. **Application Layer** – Asynchronous web server handling authentication requests


---

##  Hardware Used

* **ESP32 DevKit V1** – Main microcontroller with integrated Wi-Fi connectivity
* **5V Relay Module** – Controls simulated locking mechanism
* **SG90 Micro Servo** – Simulates mechanical lock movement
* **Red and Green LEDs** – Visual access status indicators
* **220Ω Resistors** – LED current protection
* **Breadboard & Jumpers** – Rapid prototyping setup
* **Micro-USB Cable** – Power supply and firmware upload

---

##  Security Features

* WPA2 network isolation
* Server-side PIN validation
* Temporary lock after three failed attempts
* Disabled browser autocomplete for credential protection

---

##  Team Members

| Name                              | Role          |
| --------------------------------- | ------------- |
| Daniela Jhoan Rosas Landeros      | Hardware Lead |
| Lizbeth Andrea Castillo Maldonado | Software Lead |

---

## Actualización Final Sprint 3
- PIN: 0307
- LED Rojo: GPIO 5
- Red: Cerradura Inteligente
