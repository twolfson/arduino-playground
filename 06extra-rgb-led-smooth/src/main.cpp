// Load in our dependencies
#include "Arduino.h"

// Define our structures
struct color_t {
  char red;
  char green;
  char blue;
};

// Define our constants
// DEV: We use pins 9-11 as they're all PWM
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;
color_t COLOR_RED = {red: 100, green: 0, blue: 0};
color_t COLOR_GREEN = {red: 0, green: 100, blue: 0};
color_t COLOR_BLUE = {red: 0, green: 0, blue: 100};
color_t COLOR_ARRAY[3] = {
  COLOR_RED, COLOR_GREEN, COLOR_BLUE
};
int STEP_DURATION = 3000; // ms

// Define our helpers
// TODO: Is `char` the proper data-type? Does C++ have something like `byte` or `uint4`?
void colorWrite(color_t color) {
  // Output our individual colors directly to their pins
  analogWrite(RED_PIN, color.red);
  analogWrite(GREEN_PIN, color.green);
  analogWrite(BLUE_PIN, color.blue);
}

// Define our main logic
int current_red = 0;
int current_green = 0;
int current_blue = 0;
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
  colorWrite(COLOR_ARRAY[0]);
  delay(STEP_DURATION);
  colorWrite(COLOR_ARRAY[1]);
  delay(STEP_DURATION);
  colorWrite(COLOR_ARRAY[2]);
  delay(STEP_DURATION);
}
