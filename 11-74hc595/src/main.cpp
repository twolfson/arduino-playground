// Load in our dependencies
#include "Arduino.h"

// Define our constants
const int CLOCK_PIN = 8;
const int DATA_PIN = 11;
const int LATCH_PIN = 12;

const int A_VALUE = 0b10000000;
const int B_VALUE = 0b00000001;
const int C_VALUE = 0b00001000;
const int D_VALUE = 0b00000100;
const int E_VALUE = 0b00000010;
const int F_VALUE = 0b01000000;
const int G_VALUE = 0b00100000;
const int DECIMAL_VALUE = 0b00010000;

char HORIZ_CHAR = '-';
char VERT_CHAR = '|';
char DECIMAL_CHAR = '.';
char ONE_DRAWING[5][4] = {
  "   ",
  "  |",
  "   ",
  "  |",
  "   ",
};
char TWO_DRAWING[5][4] = {
  " - ",
  "  |",
  " - ",
  "|  ",
  " - ",
};
char TWO_DECIMAL_DRAWING[5][4] = {
  " - ",
  "  |",
  " - ",
  "|  ",
  " -.",
};
char EIGHT_DECIMAL_DRAWING[5][4] = {
  " - ",
  "| |",
  " - ",
  "| |",
  " -.",
};
char LOOP_SEQUENCE_DRAWINGS[6][5][4] = {
  {
    " - ",
    "   ",
    "   ",
    "   ",
    "   ",
  },
  {
    "   ",
    "  |",
    "   ",
    "   ",
    "   ",
  },
  {
    "   ",
    "   ",
    "   ",
    "  |",
    "   ",
  },
  {
    "   ",
    "   ",
    "   ",
    "   ",
    " - ",
  },
  {
    "   ",
    "   ",
    "   ",
    "|  ",
    "   ",
  },
  {
    "   ",
    "|  ",
    "   ",
    "   ",
    "   ",
  },
};

// Define helper logic
void drawingWrite(char drawing[5][4]) {
  // Calculate our drawing value
  char drawing_val = 0b00000000;

  // Clockwise outer loop first
  if (drawing[0][1] == HORIZ_CHAR) { drawing_val |= A_VALUE; }
  if (drawing[1][2] == VERT_CHAR) { drawing_val |= B_VALUE; }
  if (drawing[3][2] == VERT_CHAR) { drawing_val |= C_VALUE; }
  if (drawing[4][1] == HORIZ_CHAR) { drawing_val |= D_VALUE; }
  if (drawing[3][0] == VERT_CHAR) { drawing_val |= E_VALUE; }
  if (drawing[1][0] == VERT_CHAR) { drawing_val |= F_VALUE; }

  // Horizontal line and decimal second
  if (drawing[2][1] == HORIZ_CHAR) { drawing_val |= G_VALUE; }
  if (drawing[4][2] == DECIMAL_CHAR) { drawing_val |= DECIMAL_VALUE; }

  // Signal to IC that we are writing data
  digitalWrite(LATCH_PIN, LOW);

  // Output our data
  // DEV: This uses a clock signal to move data along
  // DEV: MSBFIRST means most significant byte first which declares the order of our output
  //   i.e. 01111111 being output as 01111111 or 11111110
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, drawing_val);

  // Signal to IC that we are done writing data
  digitalWrite(LATCH_PIN, HIGH);
}

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
  // Draw some numbers
  drawingWrite(ONE_DRAWING);
  delay(1000);
  drawingWrite(TWO_DRAWING);
  delay(1000);
  drawingWrite(EIGHT_DECIMAL_DRAWING);
  delay(1000);

  // Draw a looping sequence
  int loop_count = 3;
  int len = sizeof(LOOP_SEQUENCE_DRAWINGS)/sizeof(*LOOP_SEQUENCE_DRAWINGS);
  for (int i = 0; i < loop_count; i += 1) {
    for (int j = 0; j < len; j += 1) {
      drawingWrite(LOOP_SEQUENCE_DRAWINGS[j]);
      delay(100);
    }
  }
}
