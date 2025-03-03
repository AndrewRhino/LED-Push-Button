# Tinkercad Reaction Time Game

This project is an Arduino-based reaction time game created in Tinkercad. It measures how quickly a user can press a button after an LED lights up, with the wait time randomized between 3 and 6 seconds. The reaction time is displayed in milliseconds via the Serial Monitor.

## Overview

- **Purpose**: Test and measure reaction time.
- **Components**:
  - LED connected to pin 13.
  - Pushbutton connected to pin 2.
- **Platform**: Designed and simulated in Tinkercad Circuits, compatible with real Arduino hardware.

## Hardware Setup

### Components Needed
- Arduino board (e.g., Arduino Uno)
- LED
- Pushbutton
- 220-ohm resistor (for the LED)
- Jumper wires

### Wiring
1. **LED**:
   - Positive leg (anode) to Arduino pin 13 via a 220-ohm resistor.
   - Negative leg (cathode) to GND.
2. **Pushbutton**:
   - One leg to Arduino pin 2.
   - Opposite leg to GND (no pull-up resistor needed; uses internal pull-up implicitly via `INPUT` mode).
3. **Serial Monitor**: Ensure the Arduino is connected to a computer to view output.

### Tinkercad Simulation
- In Tinkercad Circuits, drag an Arduino Uno, LED, resistor, and pushbutton onto the workspace.
- Connect as described above.
- Open the Code editor, switch to Text mode, and paste the provided code.

## Code Explanation

The code consists of three main parts:

1. **Global Variables**:
   - `ledPIN = 13`: Pin for the LED.
   - `buttonPIN = 2`: Pin for the pushbutton.
   - `time`: Stores the reaction time in milliseconds.

2. **Setup Function**:
   - Configures `ledPIN` as an output and `buttonPIN` as an input.
   - Initializes Serial communication at 9600 baud.

3. **Loop Function**:
   - Prints "Get ready..." to the Serial Monitor.
   - Calls `light_on()` to handle the LED flash and button press timing.
   - Displays the reaction time.
   - Waits 2 seconds before the next round.

4. **light_on Function**:
   - Waits a random delay (3–6 seconds).
   - Turns on the LED and records the start time.
   - Waits for the button to be pressed, then calculates the reaction time.
   - Turns off the LED and returns the reaction time.

### Code
```cpp
int ledPIN = 13;
int buttonPIN = 2;
int time = 0;

void setup() {
  pinMode(ledPIN, OUTPUT);
  pinMode(buttonPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Get ready...");
  time = light_on();
  Serial.print("Reaction time = ");
  Serial.print(time);
  Serial.print("ms\n");
  delay(2000);
}

int light_on() {
  int num = random(3000, 6000);
  delay(num);
  digitalWrite(ledPIN, 1);
  unsigned long startTime = millis();
  while (digitalRead(buttonPIN) != 1) {
    // wait for button press
  }
  unsigned long endTime = millis();
  unsigned long buttonTime = endTime - startTime;
  digitalWrite(ledPIN, 0);
  return buttonTime;
}
