// Load in our dependencies
#include "Arduino.h"

// DEV: The initial setup of requires precise wiring
//   which is a pain to manually debug
//   We've decided to circumvent that via smarter register data

// Define our structures
struct register_mask_t {
  char register_1;
  char register_2;
};

// Define our constants
const int CLOCK_PIN = 12;
const int DATA_PIN = 11;
const int LATCH_PIN = 8;

register_mask_t ROW_1  = {register_1: 0b01000000, register_2: 0b00000000};
register_mask_t ROW_2  = {register_1: 0b00010000, register_2: 0b00000000}; // DEAD
register_mask_t ROW_3  = {register_1: 0b00000100, register_2: 0b00000000};
register_mask_t ROW_4  = {register_1: 0b10000000, register_2: 0b00000000};
register_mask_t ROW_5  = {register_1: 0b00100000, register_2: 0b00000000};
register_mask_t ROW_6  = {register_1: 0b00001000, register_2: 0b00000000}; // DEAD
register_mask_t ROW_7  = {register_1: 0b00000000, register_2: 0b00010000};
register_mask_t ROW_8  = {register_1: 0b00000000, register_2: 0b00000100};
register_mask_t ROWS[8] = {ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8};

// DEV: These black out an LED row, we need to invert them with the other columns to get their true value
register_mask_t _COL_1 = {register_1: 0b00000000, register_2: 0b00000001};
register_mask_t _COL_2 = {register_1: 0b00000001, register_2: 0b00000000};
register_mask_t _COL_3 = {register_1: 0b00000000, register_2: 0b00000010};
register_mask_t _COL_4 = {register_1: 0b00000000, register_2: 0b00001000};
register_mask_t _COL_5 = {register_1: 0b00000010, register_2: 0b00000000};
register_mask_t _COL_6 = {register_1: 0b00000000, register_2: 0b00100000};
register_mask_t _COL_7 = {register_1: 0b00000000, register_2: 0b01000000};
register_mask_t _COL_8 = {register_1: 0b00000000, register_2: 0b10000000};

register_mask_t _ALL_COLS = {register_1: 0b00000011, register_2: 0b011101011};
register_mask_t COL_1 = {register_1: _ALL_COLS.register_1 ^ _COL_1.register_1, register_2: _ALL_COLS.register_2 ^ _COL_1.register_2};
register_mask_t COL_2 = {register_1: _ALL_COLS.register_1 ^ _COL_2.register_1, register_2: _ALL_COLS.register_2 ^ _COL_2.register_2};
register_mask_t COL_3 = {register_1: _ALL_COLS.register_1 ^ _COL_3.register_1, register_2: _ALL_COLS.register_2 ^ _COL_3.register_2};
register_mask_t COL_4 = {register_1: _ALL_COLS.register_1 ^ _COL_4.register_1, register_2: _ALL_COLS.register_2 ^ _COL_4.register_2};
register_mask_t COL_5 = {register_1: _ALL_COLS.register_1 ^ _COL_5.register_1, register_2: _ALL_COLS.register_2 ^ _COL_5.register_2};
register_mask_t COL_6 = {register_1: _ALL_COLS.register_1 ^ _COL_6.register_1, register_2: _ALL_COLS.register_2 ^ _COL_6.register_2};
register_mask_t COL_7 = {register_1: _ALL_COLS.register_1 ^ _COL_7.register_1, register_2: _ALL_COLS.register_2 ^ _COL_7.register_2};
register_mask_t COL_8 = {register_1: _ALL_COLS.register_1 ^ _COL_8.register_1, register_2: _ALL_COLS.register_2 ^ _COL_8.register_2};
register_mask_t COLS[8] = {COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8};

//Define some images
char X_CHAR = 'x';
char BORDER_IMAGE[8][8] = {
  "xxxxxxxx",
  "x      x",
  "x      x",
  "x      x",
  "x      x",
  "x      x",
  "x      x",
  "xxxxxxxx",
};
char TOP_LEFT_DIAGONAL_IMAGE[8][8] = {
  "x       ",
  " x      ",
  "  x     ",
  "   x    ",
  "    x   ",
  "     x  ",
  "      x ",
  "       x",
};
char BOTTOM_LEFT_DIAGONAL_IMAGE[8][8] = {
  "       x",
  "      x ",
  "     x  ",
  "    x   ",
  "   x    ",
  "  x     ",
  " x      ",
  "x       ",
};

// Define helper logic

void imageWrite(char image[8][8]) {
  // TODO: Parameterize row/col counts
  for (int i = 0; i < 8; i += 1) {
    for (int j = 0; j < 8; j += 1) {
      if (image[i][j] == X_CHAR) {
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROWS[i].register_1 | COLS[j].register_1);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROWS[i].register_2 | COLS[j].register_2);
      } else {
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
      }
      digitalWrite(LATCH_PIN, HIGH);
      digitalWrite(LATCH_PIN, LOW);
    }
  }
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
  for (int i = 0; i < 100; i += 1) {
    delay(1);
    imageWrite(BORDER_IMAGE);
  }
  for (int i = 0; i < 100; i += 1) {
    delay(1);
    imageWrite(TOP_LEFT_DIAGONAL_IMAGE);
  }
  for (int i = 0; i < 100; i += 1) {
    delay(1);
    imageWrite(BOTTOM_LEFT_DIAGONAL_IMAGE);
  }
}
