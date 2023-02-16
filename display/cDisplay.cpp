#include "cDisplay.hpp"

cDisplay::cDisplay() {
  LCD_I2C_Setup (i2c_default, LCD_SDA_PIN, LCD_SCL_PIN, I2C_SPEED);
  display = std::make_unique<LCD_I2C>(LCD_ADDRESS, LCD_MAX_CHARS, LCD_MAX_LINES, i2c_default);
  }


void
cDisplay::clear() {
  display->clear();
  }


void
cDisplay::clearLine(int line) {
  char space[LCD_MAX_CHARS] = {" "};
  display->setCursor(line, 0);
  display->writeString(space, false);
  }


void
cDisplay::printLine(int line, int pos, const char* text) {
  display->setCursor(line, pos);
  display->writeString(text, false);
  }


void
cDisplay::setBacklight(int flag) {
  display->setBacklight(flag);
  }


void
cDisplay::Init() {

  display->clear();
  sleep_ms(2000);
  printLine(1,3,INIT_MESSAGE);

  for (int i=0; i<10; i++) {
    display->setBacklight(1);
    sleep_ms(500);
    display->setBacklight(0);
    sleep_ms(500);
    }
  display->setBacklight(1);
  }


eWorkmodes
cDisplay::selectMode() {
  return eDistillation1;
  }
