
# Software Requirements Specification

Secure Access Management System

---

## 1. Introduction

### 1.1 Purpose

This document defines the functional and non-functional requirements of the secure access control system based on ESP32.

### 1.2 Scope

The system will authenticate users via a web interface hosted locally on the ESP32 and control a physical actuator after successful validation.

---

## 2. Overall Description

### 2.1 Product Perspective

The system operates as an autonomous embedded device integrating:

* Microcontroller
* Web server
* Wi-Fi connectivity
* Physical actuator

### 2.2 Users

* Authorized user
* System administrator

---

## 3. Functional Requirements

RF1: The system shall generate a web server on port 80.
RF2: The system shall display a login form.
RF3: The system shall validate the PIN internally.
RF4: The system shall activate the actuator if authentication is successful.
RF5: The system shall block access after three failed attempts.

---

## 4. Non-Functional Requirements

RNF1: The system shall respond within 3 seconds.
RNF2: The system shall operate under WPA2 encryption.
RNF3: The system shall run without external servers.

---

