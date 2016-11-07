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
  int BUTTON_VAL = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, BUTTON_VAL);
}
