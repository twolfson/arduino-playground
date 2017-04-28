// Load in our dependencies
#include "Arduino.h"
#include "LiquidCrystal.h"

// DEV: We are unable to verify this works yet
//   all the wires look correct
//   but we are guessing there's an issue due to unsoldered LCD connections

// Define our constants
int LCD_COLUMNS = 16;
int LCD_ROWS = 2;
// https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/08.LCD1602.ino#L8-L9
// TODO: Why are these strings 26 characters long?
const int STRING_LENGTH = 27;
char SUNFOUNDER_STRING[STRING_LENGTH] = " SUNFOUNDER               ";
char HELLO_WORLD_STRING[STRING_LENGTH] = "hello, world!             ";

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
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
}

void loop()
{
  // Draw our first string to our display
  // https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino/blob/d38b2f2d8d64a420f4123d0a9e2b713b705e19f4/08.LCD1602.ino#L21-L35
  lcd.setCursor(LCD_COLUMNS - 1, 0);
  for (int string_index = 0; string_index < STRING_LENGTH; string_index += 1) {
    lcd.scrollDisplayLeft();
    lcd.print(SUNFOUNDER_STRING[string_index]);
    delay(1000);
  }

  // Clear our LCD
  lcd.clear();

  // Draw our second string to our display
  lcd.setCursor(LCD_COLUMNS - 1, 1);
  for (int string_index = 0; string_index < STRING_LENGTH; string_index += 1) {
    lcd.scrollDisplayLeft();
    lcd.print(HELLO_WORLD_STRING[string_index]);
    delay(1000);
  }

  // Clear our LCD
  lcd.clear();
}
