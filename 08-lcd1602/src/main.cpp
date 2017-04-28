// Load in our dependencies
#include "Arduino.h"
#include "LiquidCrystal.h"

// Define our constants
int LCD_COLUMNS = 16;
int LCD_ROWS = 2;
// TODO: Add assert for string length
char SUNFOUNDER_STRING[] = " SUNFOUNDER               ";
char HELLO_WORLD_STRING[] = "hello, world!             ";

// Define our LCD singleton
LiquidCrystal lcd(
  4, // RS pin
  6, // E pin
  10, 11, 12, 13 // DB4-7 pins
);

// Define our main logic
void setup()
{
  // Initialize our LCD
  lcd.beg ing(LCD_COLUMNS, LCD_ROWS);
}

void loop()
{
  // Clear our LCD
  lcd.clear();
}
