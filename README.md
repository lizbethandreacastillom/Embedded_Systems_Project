Secure Access Management System

Embedded Systems Project

 Project Overview

This project consists of the design and implementation of a secure access control system using an ESP32 microcontroller as a Micro Web Server (MWS).

The system allows users to scan a QR code to access a locally hosted web interface. After entering a PIN, the ESP32 validates the credentials and activates a physical actuator (relay or servo motor) to simulate door unlocking.

The system integrates embedded programming, networking, and cybersecurity concepts in a single autonomous device.

 Objective

To design and implement a secure embedded access control system that:

Hosts its own web server

Authenticates users via PIN

Controls a physical actuator

Implements brute-force protection

Operates independently without cloud services

 System Architecture

The system is divided into three main layers:

Hardware Layer – ESP32, relay, servo motor, LEDs

Network Layer – Wi-Fi AP mode with WPA2 security

Application Layer – Asynchronous web server handling authentication requests

 Detailed requirements and architecture documentation can be found here:
 docs/architecture/requirements/SRS.md

Hardware Used

ESP32 DevKit V1 – Main microcontroller with integrated Wi-Fi

5V Relay Module – Controls simulated locking mechanism

SG90 Micro Servo – Simulates mechanical lock movement

Red and Green LEDs – Status indication

220Ω Resistors – LED protection

Breadboard & Jumpers – Prototyping

Micro-USB Cable – Power and firmware upload

 Security Features

WPA2 network isolation

Server-side PIN validation

Temporary lock after 3 failed attempts

No credential storage in browser
