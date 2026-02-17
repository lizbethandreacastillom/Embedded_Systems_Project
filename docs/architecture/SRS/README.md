

---

# Software Requirements Specification (SRS)

**Secure Access Management System using ESP32**

Version 1.0
Embedded Systems – 8°A

---

# 1. Introduction

## 1.1 Purpose

This document defines the functional and non-functional requirements of the Secure Access Management System based on an ESP32 microcontroller operating as a Micro Web Server.

The purpose of this system is to provide secure electronic access control through PIN-based authentication using a locally hosted web interface.

---

## 1.2 Scope

The system will:

* Host a web server on the ESP32.
* Allow users to connect via Wi-Fi.
* Provide a web interface for PIN entry.
* Validate credentials internally.
* Activate a physical actuator upon successful authentication.
* Implement basic cybersecurity protections.

The system operates autonomously without requiring external cloud services.

---

## 1.3 Definitions, Acronyms and Abbreviations

| Term  | Definition                            |
| ----- | ------------------------------------- |
| ESP32 | Microcontroller with integrated Wi-Fi |
| MWS   | Micro Web Server                      |
| GPIO  | General Purpose Input/Output          |
| PIN   | Personal Identification Number        |
| WPA2  | Wi-Fi Protected Access 2              |

---

# 2. Overall Description

## 2.1 Product Perspective

The system is a standalone embedded device composed of:

* Hardware Layer (ESP32, actuators, LEDs)
* Network Layer (Wi-Fi AP mode with WPA2 encryption)
* Application Layer (Asynchronous Web Server)

It does not depend on external infrastructure beyond power supply.

---

## 2.2 Product Functions

The system performs the following functions:

* Generates a local Wi-Fi network.
* Displays a QR code containing device IP.
* Hosts a login web interface.
* Validates user PIN.
* Activates locking mechanism.
* Registers failed attempts.
* Temporarily blocks access after multiple failures.

---

## 2.3 User Classes and Characteristics

### Authorized User

* Connects to the Wi-Fi network.
* Scans QR code.
* Enters PIN to gain access.

### System Administrator

* Configures the PIN.
* Updates firmware if needed.

---

## 2.4 Operating Environment

* ESP32 DevKit V1 hardware platform
* Arduino Framework (C++)
* Local Wi-Fi network (AP Mode)
* Web browser (mobile device or laptop)

---

# 3. Functional Requirements

Each requirement is uniquely identified.

### RF-01

The system shall initialize GPIO pins during startup.

### RF-02

The system shall start a web server on port 80.

### RF-03

The system shall provide a login interface accessible via browser.

### RF-04

The system shall validate the entered PIN on the server side.

### RF-05

The system shall activate the actuator for 3–5 seconds if authentication is successful.

### RF-06

The system shall turn on the green LED when access is granted.

### RF-07

The system shall turn on the red LED when access is denied.

### RF-08

The system shall count failed authentication attempts.

### RF-09

The system shall block authentication attempts after three consecutive failures.

---

# 4. Non-Functional Requirements

### 4.1 Performance Requirements

RNF-01: The system shall respond to authentication requests within 3 seconds.
RNF-02: The actuator activation delay shall not exceed 500 milliseconds after validation.

---

### 4.2 Security Requirements

RNF-03: The system shall use WPA2 encryption for network access.
RNF-04: PIN validation logic shall be implemented exclusively server-side.
RNF-05: The system shall prevent brute-force attacks through temporary lockout.
RNF-06: The login field shall disable autocomplete functionality.

---

### 4.3 Reliability Requirements

RNF-07: The system shall operate continuously while powered.
RNF-08: The system shall recover automatically after power reset.

---

### 4.4 Hardware Constraints

RNF-09: The system shall operate within ESP32 memory limitations.
RNF-10: GPIO usage shall comply with ESP32 electrical specifications.

---

# 5. Assumptions and Dependencies

* The user possesses the Wi-Fi password.
* The device has stable power supply.
* The user accesses the interface through a modern web browser.

---


