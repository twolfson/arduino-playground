// Based on https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/03.Controlling%20LED%20By%20PWM.ino
// Load in our dependencies
#include "Arduino.h"

// Define our constants
int LED_PIN = 9;
int STEP_DURATION = 8; // ms
int LOOP_DELAY = 800; // ms

void setup()
{
  // Configure our LEDs
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Fade in our LED in stepped intervals
  int i;
  for (i = 0; i <= 255; i += 1) {
    analogWrite(LED_PIN, i);
    delay(STEP_DURATION);
  }

  // Fade out our LED in stepped intervals
  for (i = 255; i >= 0; i -= 1) {
    analogWrite(LED_PIN, i);
    delay(STEP_DURATION);
  }

  // Sleep our loop before it restarts
  delay(LOOP_DELAY);
}
