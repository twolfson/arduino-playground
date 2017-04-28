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
  digitalWrite(A_PIN, LOW);
  digitalWrite(B_PIN, LOW);
  digitalWrite(C_PIN, LOW);
  digitalWrite(D_PIN, LOW);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, LOW);
  digitalWrite(G_PIN, HIGH);
  digitalWrite(DECIMAL_PIN, LOW);
  delay(1000);
}
