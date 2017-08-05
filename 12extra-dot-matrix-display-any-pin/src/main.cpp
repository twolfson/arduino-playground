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

register_mask_t  ROW_1 = {register_1: 0b01000000, register_2: 0b00000000};
register_mask_t  ROW_2 = {register_1: 0b00010000, register_2: 0b00000000}; // DEAD
register_mask_t  ROW_3 = {register_1: 0b00000100, register_2: 0b00000000};
register_mask_t  ROW_4 = {register_1: 0b10000000, register_2: 0b00000000};
register_mask_t  ROW_5 = {register_1: 0b00100000, register_2: 0b00000000};
register_mask_t  ROW_6 = {register_1: 0b00001000, register_2: 0b00000000}; // DEAD
register_mask_t  ROW_7 = {register_1: 0b00000000, register_2: 0b00010000};
register_mask_t  ROW_8 = {register_1: 0b00000000, register_2: 0b00000100};

// DEV: These black out an LED row, we need to invert them with the other columns to get their true value
register_mask_t _COL_1 = {register_1: 0b00000000, register_2: 0b00000001};
register_mask_t _COL_2 = {register_1: 0b00000001, register_2: 0b00000000};
register_mask_t _COL_3 = {register_1: 0b00000000, register_2: 0b00000010};
register_mask_t _COL_4 = {register_1: 0b00000000, register_2: 0b00001000};
register_mask_t _COL_5 = {register_1: 0b00000010, register_2: 0b00000000};
register_mask_t _COL_6 = {register_1: 0b00000000, register_2: 0b00100000};
register_mask_t _COL_7 = {register_1: 0b00000000, register_2: 0b01000000};
register_mask_t _COL_8 = {register_1: 0b00000000, register_2: 0b10000000};

register_mask_t ALL_COLS = {register_1: 0b00000011, register_2: 0b011101011};
register_mask_t COL_1 = {register_1: ALL_COLS.register_1 ^ _COL_1.register_1, register_2: ALL_COLS.register_2 ^ _COL_1.register_2};
register_mask_t COL_2 = {register_1: ALL_COLS.register_1 ^ _COL_2.register_1, register_2: ALL_COLS.register_2 ^ _COL_2.register_2};
register_mask_t COL_3 = {register_1: ALL_COLS.register_1 ^ _COL_3.register_1, register_2: ALL_COLS.register_2 ^ _COL_3.register_2};
register_mask_t COL_4 = {register_1: ALL_COLS.register_1 ^ _COL_4.register_1, register_2: ALL_COLS.register_2 ^ _COL_4.register_2};
register_mask_t COL_5 = {register_1: ALL_COLS.register_1 ^ _COL_5.register_1, register_2: ALL_COLS.register_2 ^ _COL_5.register_2};
register_mask_t COL_6 = {register_1: ALL_COLS.register_1 ^ _COL_6.register_1, register_2: ALL_COLS.register_2 ^ _COL_6.register_2};
register_mask_t COL_7 = {register_1: ALL_COLS.register_1 ^ _COL_7.register_1, register_2: ALL_COLS.register_2 ^ _COL_7.register_2};
register_mask_t COL_8 = {register_1: ALL_COLS.register_1 ^ _COL_8.register_1, register_2: ALL_COLS.register_2 ^ _COL_8.register_2};

const int ROWS = 8;
const int IMAGES = 18;
int data[ROWS * IMAGES] = {
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*" ",0*/
  0xFF,0xC1,0xBE,0xBE,0xBE,0xC1,0xFF,0xFF,
  0xFF,0xDF,0xDF,0x80,0xFF,0xFF,0xFF,0xFF,/*"1",2*/
  0xFF,0xDC,0xBC,0xBA,0xB6,0xCE,0xFF,0xFF,/*"2",3*/
  0xFF,0xDD,0xBE,0xB6,0xB6,0xC9,0xFF,0xFF,/*"3",4*/
  0xFB,0xF3,0xEB,0xDB,0x80,0xFB,0xFF,0xFF,/*"4",5*/
  0xFF,0x8D,0xAE,0xAE,0xAE,0xB1,0xFF,0xFF,/*"5",6*/
  0xFF,0xC1,0x96,0xB6,0xB6,0xD9,0xFF,0xFF,/*"6",7*/
  0xFF,0xBF,0xBC,0xB3,0xAF,0x9F,0xFF,0xFF,/*"7",8*/
  0xFF,0xC9,0xB6,0xB6,0xB6,0xC9,0xFF,0xFF,/*"8",9*/
  0xFF,0xCD,0xB6,0xB6,0xB4,0xC1,0xFF,0xFF,/*"9",10*/
  0xFC,0xF3,0xCB,0x9B,0xEB,0xF3,0xFC,0xFF,/*"A",11*/
  0xFF,0x80,0xB6,0xB6,0xB6,0xB6,0xC9,0xFF,/*"B",12*/
  0xFF,0xE3,0xDD,0xBE,0xBE,0xBE,0xBE,0xDD,/*"C",13*/
  0xFF,0x80,0xBE,0xBE,0xBE,0xBE,0xDD,0xE3,/*"D",14*/
  0xFF,0x80,0xB6,0xB6,0xB6,0xB6,0xBE,0xFF,/*"E",15*/
  0xFF,0x80,0xB7,0xB7,0xB7,0xB7,0xBF,0xFF,/*"F",16*/
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*" ",0*/
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
  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_1.register_1 | COL_1.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_1.register_2 | COL_1.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_2.register_1 | COL_2.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_2.register_2 | COL_2.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_3.register_1 | COL_3.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_3.register_2 | COL_3.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_4.register_1 | COL_4.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_4.register_2 | COL_4.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_5.register_1 | COL_5.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_5.register_2 | COL_5.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_6.register_1 | COL_6.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_6.register_2 | COL_6.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_7.register_1 | COL_7.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_7.register_2 | COL_7.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);

  delay(1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_8.register_1 | COL_8.register_1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ROW_8.register_2 | COL_8.register_2);
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
}
