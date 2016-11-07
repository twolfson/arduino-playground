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
  // If the button is pressed, then turn on our LED
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  // Otherwise, turn it off
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
