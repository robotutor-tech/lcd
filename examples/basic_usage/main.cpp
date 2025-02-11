#include <Arduino.h>
#include <lcd.h>

void setup()
{
  LCD lcd;
  lcd.println("Hello, LCD!"); // first line
  delay(1000);
  lcd.println("Hello, LCD!\nHello again!"); // both lines
}

void loop()
{
}
