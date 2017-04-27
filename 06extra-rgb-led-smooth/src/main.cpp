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
color_t COLOR_RED;
color_t COLOR_GREEN;
color_t COLOR_BLUE;
// color_t COLOR_ARRAY[3] = {
//   color {red: 255, green: 0, blue: 0},
//   {red: 0, green: 255, blue: 0},
//   {red: 0, green: 0, blue: 255},
// ];
int STEP_DURATION = 10; // ms

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
  colorWrite(COLOR_RED); // #FF0000 (red only)
  delay(STEP_DURATION);
}
