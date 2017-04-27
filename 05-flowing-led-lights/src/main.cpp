// Load in our dependencies
#include "Arduino.h"

// Define our constants
int START_LED_PIN = 11;
int END_LED_PIN = 13;
int STEP_DURATION = 100; // ms

// Define our logic
void setup()
{
  // Configure our pins
  for (int led_pin = START_LED_PIN; led_pin <= END_LED_PIN; led_pin += 1) {
    pinMode(led_pin, OUTPUT);
  }
}

void loop()
{
  // For each of our LEDs in ascending order
  for (int led_pin = START_LED_PIN; led_pin <= END_LED_PIN; led_pin += 1) {
    // Turn on our LED
    // [ ][ ][ ] -> [x][ ][ ] ->... [x][x][x]
    digitalWrite(led_pin, HIGH);

    // Wait before turning on next LED
    delay(STEP_DURATION);
  }

  // For each of our LEDs in descending order
  for (int led_pin = END_LED_PIN; led_pin >= START_LED_PIN; led_pin -= 1) {
    // Turn off our LED
    // [x][x][x] -> [x][x][ ] ->... [ ][ ][ ]
    digitalWrite(led_pin, LOW);

    // Wait before turning off next LED
    delay(STEP_DURATION);
  }

  // For each of our LEDs in descending order
  for (int led_pin = END_LED_PIN; led_pin >= START_LED_PIN; led_pin -= 1) {
    // Turn on our LED
    // [ ][ ][ ] -> [ ][ ][x] ->... [x][x][x]
    digitalWrite(led_pin, HIGH);

    // Wait before turning on next LED
    delay(STEP_DURATION);
  }

  // For each of our LEDs in ascending order
  for (int led_pin = START_LED_PIN; led_pin <= END_LED_PIN; led_pin += 1) {
    // Turn off our LED
    // [x][x][x] -> [ ][x][x] ->... [ ][ ][ ]
    digitalWrite(led_pin, LOW);

    // Wait before turning off next LED
    delay(STEP_DURATION);
  }
}
