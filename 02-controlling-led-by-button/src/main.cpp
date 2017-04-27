// Derived from https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/02.Controlling%20Led%20By%20Button.ino
// Load in our dependencies
#include "Arduino.h"

// Define our constants
int BUTTON_PIN = 12;
int LED_PIN = 13;

void setup()
{
  // Configure our LEDs
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Output button press value as LED value
  // Example: BUTTON_VAL = HIGH
  //   https://github.com/arduino/Arduino/blob/1.6.12/hardware/arduino/avr/cores/arduino/Arduino.h#L40-L41
  int BUTTON_VAL = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, BUTTON_VAL);
}
