// Load in our dependencies
#include "Arduino.h"

// Define our constants
int LED = 13;

// Define our logic
void setup()
{
  // Configure our pins
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Turn our LED on temporarily
  digitalWrite(LED, HIGH);
  delay(250);

  // Turn our LED off temporarily
  digitalWrite(LED, LOW);
  delay(250);
}
