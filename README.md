# Morse Code Feedback Smart Home System for the Visually Impaired


This project involves a smart home system designed to assist visually impaired individuals. The system comprises a transmitter and receiver. The transmitter, equipped with buttons and a vibration motor for Morse code feedback, utilizes an nRF24L01 wireless module for communication. It sends signals to the receiver, which is connected to relay modules for controlling electrical appliances.


Please note that the smartphone app, created using MIT App Inventor, cannot be uploaded as the code is not provided by MIT App Inventor for apps developed through their platform

## Installation

Install this in raspberry pi pico : Sensor_&_appliance_controller.py.

Install this in the Raspberry Pi 4:  gateway_program.py

## Key features
   •	Morse Code Feedback: Buttons on the transmitter generate Morse code patterns, providing tactile feedback through a vibration motor.

   •	Wireless Transmission: The nRF24L01 wireless module enables communication between the transmitter and receiver, allowing remote control of appliances.
   
•	Relay Modules: The receiver side interfaces with relay modules, facilitating the turning on/off of electrical appliances.

  •	The system incorporates a feedback system using vibration triggered by specific Morse code sequences, serving as a form of feedback for visually impaired people.


## Usage:

Pressing specific button combinations on the transmitter sends Morse code signals. The receiver interprets the Morse code and performs corresponding actions, such as turning on/off appliances or checking the system status. The system provides a unique and accessible interface for visually impaired users to interact with their smart home environment.