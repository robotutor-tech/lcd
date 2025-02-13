#ifndef LCD_HPP
#define LCD_HPP

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCD
{
private:
  uint8_t rows = 2, cols = 16;
  LiquidCrystal_I2C *lcd;
  String createRowText(String text);

public:
  LCD() : LCD(16, 2) {};
  LCD(uint8_t lcd_cols, uint8_t lcd_rows) : LCD(0x27, lcd_cols, lcd_rows) {};
  LCD(uint8_t lcd_address, uint8_t lcd_cols, uint8_t lcd_rows);
  LCD(LiquidCrystal_I2C &lcd, uint8_t lcd_cols, uint8_t lcd_rows);
  void println(String text);
  void println(int text);
  void clear();
  void clearAndPrintln(String text);
};

#endif