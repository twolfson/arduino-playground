// Load in our dependencies
#include "Arduino.h"

// Define our constants
const int CLOCK_PIN = 12;
const int DATA_PIN = 11;
const int LATCH_PIN = 8;

const int CLOCK_SPEED = 100;
const int ROWS = 8;
const int IMAGES = 1;
const int data[ROWS] = {
  // TODO: If no lights turn on, try 0xCC
  // TODO: Comment what each of these items is
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

// Define our main logic
void setup()
{
  // Configure our pins
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void loop()
{
  for (int imageIndex = 0; imageIndex < ROWS; imageIndex += 1) {
    // TODO: Add timing repetition (we can't persist as per normal high/low)
    int dataMask = 0x01;
    for (int i = 0; i < ROWS; i += 1) {
      int num = (imageIndex * ROWS) + i;
      dataMask = dataMask << 1;
      delay(1);
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ~data[num]);
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ~dataMask);
      digitalWrite(LATCH_PIN, HIGH);
      digitalWrite(LATCH_PIN, LOW);
    }
  }
}
