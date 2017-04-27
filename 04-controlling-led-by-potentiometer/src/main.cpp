// Based on https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/04.Controlling%20led%20by%20potentiometer.ino
// Load in our dependencies
#include "Arduino.h"

// Define our constants
// DEV: POT is short for potentiometer (I believe it's jargon)
int LED_PIN = 9; // PWM
int POT_PIN = A0;
int POT_MIN = 0;
int POT_MAX = 1023;
int PWM_MIN = 0;
int PWM_MAX = 255;

void setup()
{
  // Configure our pins
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Read from our potentiometer
  int inputVal = analogRead(POT_PIN);

  // Convert our potentiometer value and output it
  int outputVal = map(inputVal, POT_MIN, POT_MAX, PWM_MIN, PWM_MAX);
  analogWrite(LED_PIN, outputVal);
}
