// Load in our dependencies
#include "Arduino.h"

// Define our constants
// DEV: We use pins 9-11 as they're all PWM
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;
int STEP_DURATION = 250; // ms

// Define our helpers
// DEV: We use `char` as it fits our size perfectly
//   http://en.cppreference.com/w/cpp/language/types
void colorWrite(unsigned char red, unsigned char green, unsigned char blue) {
  // Output our individual colors directly to their pins
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Define our main logic
void setup()
{
  // Configure our pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
  // Output basic colors
  colorWrite(255, 0, 0); // #FF0000 (red only)
  delay(STEP_DURATION);
  colorWrite(0, 255, 0); // #00FF00 (green only)
  delay(STEP_DURATION);
  colorWrite(0, 0, 255); // #0000FF (blue only)
  delay(STEP_DURATION);

  // Output complex colors
  // Taken from: https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/06.RGB%20LED.ino#L27-L41
  colorWrite(255, 0, 0); // Red
  delay(STEP_DURATION);
  colorWrite(237, 109, 0); // Orange
  delay(STEP_DURATION);
  colorWrite(255, 215, 0); // Yellow
  delay(STEP_DURATION);
  colorWrite(34, 139, 34); // Green
  delay(STEP_DURATION);
  colorWrite(0, 0, 255); // Blue
  delay(STEP_DURATION);
  colorWrite(0, 46, 90); // Indigo
  delay(STEP_DURATION);
  colorWrite(128, 0, 128); // Purple
  delay(STEP_DURATION);
}
