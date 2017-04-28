// Load in our dependencies
#include "Arduino.h"

// DEV: We decided to skip the LED portion of the example

// Define our constants
int SERIAL_DATA_RATE = 9600; // bps

// Define our LCD singleton
LiquidCrystal lcd(
  4, // RS pin
  6, // E pin
  10, 11, 12, 13 // DB4-7 pins
);

// Define our main logic
void setup()
{
  // Listen t our serial port
  Serial.begin(SERIAL_DATA_RATE);
}

void loop()
{
  // Wait for input data
  if (Serial.available() > 0) {
    // Read in our data
    string comdata = "";
    while (Serial.available() > 0) {
      comdata += char(Serial.read());
      delay(2); // TODO: Why do we need a delay?
    }

    // Output our data
    Serial.println("Received: ", comdata);
  }
}
