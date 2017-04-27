// Load in our dependencies
#include "Arduino.h"

// Define our constants
// DEV: We use pins 9-11 as they're all PWM
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;

// Define our helpers
// TODO: Is `char` the proper data-type? Does C++ have something like `byte` or `uint4`?
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
  delay(1000); // ms
  colorWrite(0, 255, 0); // #00FF00 (green only)
  delay(1000); // ms
  colorWrite(0, 0, 255); // #0000FF (blue only)
  delay(1000); // ms
}
