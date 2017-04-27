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
// DEV: We are using struct initialization for COLOR_ARRAY
//   http://en.cppreference.com/w/c/language/struct_initialization
int RED_PIN = 9;
int GREEN_PIN = 10;
int BLUE_PIN = 11;
color_t COLOR_ARRAY[] = {
  {.red = 100, .green =   0, .blue =   0}, // Red
  {.red =   0, .green = 100, .blue =   0}, // Green
  {.red =   0, .green =   0, .blue = 100}, // Blue
};
int COLOR_ARRAY_LENGTH = sizeof(COLOR_ARRAY)/sizeof(*COLOR_ARRAY);
int STEP_COLOR_DISTANCE = 10; // Only move by 10 pixels at a time (e.g. 245 -> 255)
int STEP_DURATION = 20; // ms

// Define our helpers
void colorWrite(color_t color) {
  // Output our individual colors directly to their pins
  analogWrite(RED_PIN, color.red);
  analogWrite(GREEN_PIN, color.green);
  analogWrite(BLUE_PIN, color.blue);
}

// Define our main logic
int target_index = 0;
color_t current_color {.red = 0, .green = 0, .blue = 0};
void setup()
{
  // Configure our pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
  // If we are matching our target color, then move to the next target
  color_t target_color = COLOR_ARRAY[target_index];
  if (current_color.red == target_color.red &&
      current_color.green == target_color.green &&
      current_color.blue == target_color.blue) {
    target_index = (target_index + 1) % COLOR_ARRAY_LENGTH;
  }

  // Move closer to our target colors
  if (current_color.red < target_color.red) {
    current_color.red = min(current_color.red + STEP_COLOR_DISTANCE, target_color.red);
  } else if (current_color.red > target_color.red) {
    current_color.red = max(current_color.red - STEP_COLOR_DISTANCE, target_color.red);
  }
  if (current_color.green < target_color.green) {
    current_color.green = min(current_color.green + STEP_COLOR_DISTANCE, target_color.green);
  } else if (current_color.green > target_color.green) {
    current_color.green = max(current_color.green - STEP_COLOR_DISTANCE, target_color.green);
  }
  if (current_color.blue < target_color.blue) {
    current_color.blue = min(current_color.blue + STEP_COLOR_DISTANCE, target_color.blue);
  } else if (current_color.blue > target_color.blue) {
    current_color.blue = max(current_color.blue - STEP_COLOR_DISTANCE, target_color.blue);
  }

  // Output our updated color and wait
  colorWrite(current_color);
  delay(STEP_DURATION);
}
