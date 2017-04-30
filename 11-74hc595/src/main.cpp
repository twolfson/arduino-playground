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
  digitalWrite(A_PIN, drawing[0][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(F_PIN, drawing[1][0] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(B_PIN, drawing[1][2] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(G_PIN, drawing[2][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(E_PIN, drawing[3][0] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(C_PIN, drawing[3][2] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(D_PIN, drawing[4][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(DECIMAL_PIN, drawing[4][2] == DECIMAL_CHAR ? HIGH : LOW);
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
  // Signal to IC that we are writing data
  digitalWrite(LATCH_PIN, LOW);

  // Output our data
  // DEV: This uses a clock signal to move data along
  // DEV: MSBFIRST means most significant byte first which declares the order of our output
  //   i.e. 01111111 being output as 01111111 or 11111110
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, A_VALUE);

  // Signal to IC that we are done writing data
  digitalWrite(LATCH_PIN, HIGH);

  // Sleep
  delay(1000);

  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, C_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, D_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, E_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, F_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, G_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, DECIMAL_VALUE);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);
}
