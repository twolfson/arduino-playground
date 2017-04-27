// Load in our dependencies
#include "Arduino.h"

// Something is fucky, on occasion a 1 second press/hold will turn off button but the turn it back on when press-off

// Define our constants
int BUTTON_PIN = 12;
int LED_PIN = 13;

// Define a runtime variable
bool buttonVal = LOW;
bool buttonIsPressed = false;

// Define our logic
void setup()
{
  // Configure our LEDs
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // If our button is not being pressed, exit early
  if (digitalRead(BUTTON_PIN) == LOW) {
    buttonIsPressed = false;
    return;
  }

  // Otherwise (button is pressed)
  // If the button was already being pressed, do nothing
  if (buttonIsPressed) {
    return;
  }

  // Otherwise, switch our flag and flip our button
  buttonIsPressed = true;
  buttonVal = buttonVal == HIGH ? LOW : HIGH;
  digitalWrite(LED_PIN, buttonVal);
}
