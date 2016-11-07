// Derived from https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/01.Blinking%20Led.ino
#include "Arduino.h"

int LED = 9;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED, HIGH);

  // wait for a second
  delay(250);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED, LOW);

   // wait for a second
  delay(250);
}
