# Smart Home Project Readme
![Cover](https://github.com/mhmdreda99/Smat_home_ITI/blob/master/cover.PNG)
## Overview

This Smart Home Project is designed to create a versatile home automation system using Atmega32 microcontrollers and various components. The system is capable of controlling temperature, lighting, door access, and more, all via a smartphone interface. The project consists of two main microcontrollers: MCU1 (Master) and MCU2 (Slave). This README provides an overview of the project components and its functionality.

## Components

Here's a list of components required for this project:

1. Atmega32 microcontroller - Qty: 2
2. LCD 16X2 - Qty: 1
3. Keypad 4x4 - Qty: 1
4. LM35 temperature sensor - Qty: 1
5. HC-05/06 Bluetooth module - Qty: 1
6. LDR sensor - Qty: 1
7. External EEPROM - Qty: 1
8. Limited Servo Motor - Qty: 1
9. DC Motor - Qty: 1
10. Stepper Motor - Qty: 1
11. LEDs - Qty: 8
12. Seven-Segment Display - Qty: 2

## Project Description

### Mode Selection

1. **MCU1 (Master)** will serve as the primary microcontroller responsible for user interactions and data management. Upon starting, MCU1 will present three modes to the user:
   - Open Smart System
   - Change Password
   - Add User

### Open Smart System

1. **User Authentication**:
   - If a user chooses "Open Smart System," MCU1 will request a User ID and password.
   - If the User ID is incorrect, MCU1 will prompt for a valid ID.
   - If the password is correct, the user can control home electronic devices via a smartphone.
   - If the password is incorrect, MCU1 allows three additional attempts. After three incorrect attempts, the user is returned to the main menu.

2. **MCU2 (Slave) Behaviors**:
   - MCU2 monitors various conditions:
     - If the temperature exceeds 35°C, the fan will activate.
     - Based on ambient light data from the LDR sensor, home lighting will adjust.
     - Bluetooth commands from the user's smartphone control various devices:
       - '1': Open the door (Servo motor to 180 degrees).
       - '2': Close the door (Servo motor to 0 degrees).
       - '3': Start the fan (DC motor).
       - '4': Stop the fan (DC motor).
       - '5': Open the garage door (Stepper motor to 270 degrees).
       - '6': Close the garage door (Stepper motor returns to the previous position).
       - "Open light": Turn on the lights (8 LEDs).
       - "Close light": Turn off the lights (8 LEDs).

3. **Additional Notes**:
   - Communication between MCU1 and MCU2 occurs via SPI protocol.
   - User passwords are stored in non-volatile memory (External EEPROM).
   - Temperature is displayed on two Seven-Segment Displays.
   - Timer-based delays are used instead of `_delay_ms` function.

### Change Password

1. **Password Change Process**:
   - To change the password, MCU1 asks for the User ID and the current password.
   - If the User ID is incorrect, MCU1 will prompt for a valid ID.
   - If the current password is correct, the user can set a new password.
   - If the current password is incorrect, MCU1 allows one more attempt. After that, the user is returned to the main menu.

### Add User

1. **User Addition Process**:
   - To add a new user, MCU1 asks for a User ID, User Password, and confirmation.
   - If the confirmation password matches, the user is added to the system.
   - If the confirmation password is incorrect, MCU1 prints "Wrong password" and returns to the main menu.

## Conclusion

This Smart Home Project offers a comprehensive home automation solution using Atmega32 microcontrollers and various components. Users can control various devices within their home through a smartphone interface, ensuring convenience, security, and energy efficiency.

## Authors
* **Kareem Zidan** - [KarimZidan007](https://github.com/KarimZidan007)
* **Mohamed Reda** - [mhmdreda99](https://github.com/mhmdreda99)


See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details