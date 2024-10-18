# Arduino Calculator with Keypad and LCD Display

### Project Overview

This project involves building a simple calculator using an Arduino, a 4x4 matrix keypad, and a 16x2 LCD. The calculator performs basic arithmetic operations like addition, subtraction, multiplication, and division. The input is taken from the keypad, and results are displayed on the LCD screen.

### Components Used:

* Arduino UNO: The microcontroller used to control the components.

* 16x2 LCD Display: Displays input numbers, operators, and results.

* 4x4 Matrix Keypad: Allows user input for numbers and operations.

* Wires: For connecting components.

* Circuit Diagram

The calculator circuit was designed using Tinkercad. Refer to the diagram below:
<img width="781" alt="Screenshot 2024-10-18 at 1 26 31 PM" src="https://github.com/user-attachments/assets/be0474d6-2018-446a-997c-d43211b7f2a6">

### Pin Connections:

 **LCD Pins:**
* RS, RW, ENA, DB0-DB7 → Arduino Digital Pins.
* VCC, GND → Power and Ground.

 **Keypad Pins:**
* Rows connected to Arduino Pins 8-11.
* Columns connected to Pins 12, 13, A0, A1.

### Features:

* Basic Arithmetic: Supports addition (+), subtraction (-), multiplication (*), and division (/).

* Error Handling: Displays an error when attempting division by zero.

* Reset Function: Pressing C clears the display and resets the calculator.

### How It Works:

* The user inputs numbers and operations using the keypad.
* The input is displayed on the 16x2 LCD.
* Upon pressing the # key, the result of the operation is displayed.
* For square root calculations, pressing the dedicated button reads the first number and displays its square root

### Picture of the circuit in Tinkercad: 
<img width="649" alt="Screenshot 2024-10-18 at 1 32 03 PM" src="https://github.com/user-attachments/assets/63714856-cb37-4f25-abe1-5e96e5adfe16">
