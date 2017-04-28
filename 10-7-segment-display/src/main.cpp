// Load in our dependencies
#include "Arduino.h"

// Define our constants
int A_PIN = 11;
int B_PIN = 12;
int C_PIN = 7;
int D_PIN = 6;
int E_PIN = 5;
int F_PIN = 10;
int G_PIN = 9;
int DECIMAL_PIN = 8;

char HORIZ_CHAR = "-";
char VERT_CHAR = "|";
char DECIMAL_CHAR = ".";
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

// Define helper logic
void drawingWrite(char drawing[5][4]) {
  digitalWrite(A_PIN, drawing[0][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(B_PIN, drawing[1][0] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(C_PIN, drawing[1][2] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(D_PIN, drawing[2][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(E_PIN, drawing[3][0] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(F_PIN, drawing[3][2] == VERT_CHAR ? HIGH : LOW);
  digitalWrite(G_PIN, drawing[4][1] == HORIZ_CHAR ? HIGH : LOW);
  digitalWrite(DECIMAL_PIN, drawing[4][2] == DECIMAL_CHAR ? HIGH : LOW);
}

// Define our main logic
void setup()
{
  // Configure our pins
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  pinMode(D_PIN, OUTPUT);
  pinMode(E_PIN, OUTPUT);
  pinMode(F_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(DECIMAL_PIN, OUTPUT);
}

void loop()
{
  // Draw a "1"
  drawingWrite(ONE_DRAWING);
  delay(1000);
}
