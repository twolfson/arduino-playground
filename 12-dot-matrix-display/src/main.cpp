// Load in our dependencies
#include "Arduino.h"

// Define our constants
const int CLOCK_PIN = 12;
const int DATA_PIN = 11;
const int LATCH_PIN = 8;

int data[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*" ",0*/
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
              0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*" ",0*/};/*"0",1*/

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
  for (int n = 0; n < 136; n += 1) {
    for(int t = 0; t < 10; t += 1) {
      int dat = 0x01;
      for (int num = n; num < 8 + n; num += 1) {
        dat = dat << 1;
        delay(1);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ~data[num + 0]);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, ~dat);
        digitalWrite(LATCH_PIN, HIGH);
        digitalWrite(LATCH_PIN, LOW);
      }
    }
  }
}