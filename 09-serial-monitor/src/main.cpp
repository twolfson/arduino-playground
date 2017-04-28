// Load in our dependencies
#include "Arduino.h"

// DEV: We decided to skip the LED portion of the example

// Define our constants
int SERIAL_DATA_RATE = 9600; // bps
String PROMPT = "Type into the serial monitor";

// Define our main logic
void setup()
{
  // Listen t our serial port
  Serial.begin(SERIAL_DATA_RATE);

  // Prompt for initial input
  Serial.println(PROMPT);
}

void loop()
{

  // Wait for input data
  if (Serial.available() > 0) {
    // Read in our data
    String comdata = "";
    while (Serial.available() > 0) {
      comdata += char(Serial.read());
    }

    // Output our data
    Serial.println("Received: " + comdata);
  }
}
