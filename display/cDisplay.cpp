#include "cDisplay.hpp"
#include "translations.hpp"

cDisplay::cDisplay() {
  LCD_I2C_Setup (i2c_default, LCD_SDA_PIN, LCD_SCL_PIN, I2C_SPEED);
  display = std::make_unique<LCD_I2C>(LCD_ADDRESS, LCD_MAX_CHARS, LCD_MAX_LINES, i2c_default);
  }


cDisplay::~cDisplay() {
  }


void
cDisplay::Init() {

  display->clear();
  sleep_ms(2000);
  display->setCursor(1, 3);
  display->writeString(INIT_MESSAGE, true);

  for (int i=0; i<10; i++) {
    display->setBacklight(1);
    sleep_ms(500);
    display->setBacklight(0);
    sleep_ms(500);
    }
  }


eWorkmodes
cDisplay::selectMode() {
  return eDistillation1;
  }
