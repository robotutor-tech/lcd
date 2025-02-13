#include "lcd.h"

LCD::LCD(uint8_t lcd_address, uint8_t lcd_cols, uint8_t lcd_rows)
{
  this->rows = lcd_rows;
  this->cols = lcd_cols;
  this->lcd = new LiquidCrystal_I2C(lcd_address, lcd_cols, lcd_rows);
  this->lcd->init();
  this->lcd->backlight();
}

LCD::LCD(LiquidCrystal_I2C &lcd, uint8_t lcd_cols, uint8_t lcd_rows) : lcd(&lcd), cols(lcd_cols), rows(lcd_rows) {}

String LCD::createRowText(String text)
{
  String result = text.substring(0, this->cols);
  for (uint8_t i = result.length(); i < this->cols; i++)
  {
    result += " ";
  }
  return result;
}

void LCD::println(String text)
{
  if (text.indexOf("\n") == -1)
  {
    this->lcd->setCursor(0, 0);
    this->lcd->print(this->createRowText(text));
    return;
  }
  for (uint8_t i = 0; i < this->rows; i++)
  {
    this->lcd->setCursor(0, i);
    uint8_t index = text.indexOf("\n");
    if (index == -1)
    {
      this->lcd->print(this->createRowText(text));
    }
    else
    {
      String printableString = text.substring(0, index);
      this->lcd->print(this->createRowText(printableString));
      text = text.substring(index + 1);
    }
  }
}

void LCD::clearAndPrintln(String text)
{
  this->clear();
  this->println(text);
}

void LCD::clear()
{
  this->lcd->clear();
}

void LCD::println(int number)
{
  this->println(String(number));
}