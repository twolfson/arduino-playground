// Based on https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/03.Controlling%20LED%20By%20PWM.ino
// Load in our dependencies
#include "Arduino.h"

// Define our constants
// DEV: LED_PIN must support PWM (i.e. 3, 5, 6, 9, 10, 11)
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
    // DEV: analogWrite outputs full voltage for i/256 of PWM frequency
    //   Based on docs, this is 490Hz for most Arduino pins
    //     except Uno has 5/6 with 980Hz and Leonardo has 3/11 with 980Hz
    //     This means we can get finer control on the 980Hz pins
    //   https://www.arduino.cc/en/Reference/analogWrite
    //   https://www.arduino.cc/en/Tutorial/PWM
    // DEV: PWM operates based on persistence of vision
    //   so we see a light on at full voltage for i/256 * 1/490s = i/(256*490)s
    //   but we think it's set to a low voltage for the whole time
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
