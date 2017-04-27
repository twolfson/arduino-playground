// Load in our dependencies
#include "Arduino.h"

// Define our constants
int MOTOR_IN_1_PIN = 9;
int MOTOR_IN_2_PIN = 10;

// Define our helpers
void motorWrite(unsigned int speed, bool counterClockwise = false) {
  // If we are turning clockwise
  if (counterClockwise === false) {
    // Enable our clockwise input and disable counter-clockwise input
    analogWrite(MOTOR_IN_1_PIN, speed);
    analogWrite(MOTOR_IN_2_PIN, 0);
  // Otherwise (counter-clockwise)
  } else {
    // Enable our counter-clockwise input and disable clockwise input
    analogWrite(MOTOR_IN_2_PIN, speed);
    analogWrite(MOTOR_IN_1_PIN, 0);
  }
}

// Define our main logic
void setup()
{
  // Configure our pins
  pinMode(MOTOR_IN_1_PIN, OUTPUT);
  pinMode(MOTOR_IN_2_PIN, OUTPUT);
}

void loop()
{
  // Start turning our motor clockwise
  motorWrite(200, false);
  delay(1000);

  // Then, turn our motor counter-clockwise
  motorWrite(200, true);
  delay(1000);
}
