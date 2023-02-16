#ifndef __cDisplay_hpp__
#define __cDisplay_hpp__

#include "hardware/i2c.h"
#include "LCD_I2C.hpp"
#include <memory>
#include <eWorkmode.hpp>

#ifdef LANG_RUSSIAN
#define INIT_MESSAGE "\xA5\xBD\xB8\xE5\xB8\x61\xBB\xB8\xB7\x61\xE5\xB8\xC7\x10"
#else
#define INIT_MESSAGE "Initialization\x10"
#endif

#ifndef LCD_SDA_PIN
#define LCD_SDA_PIN PICO_DEFAULT_I2C_SDA_PIN
#endif

#ifndef LCD_SCL_PIN
#define LCD_SCL_PIN PICO_DEFAULT_I2C_SCL_PIN
#endif

// Display 20x4 I2C (Hitachi HD44780 - like)
#ifndef LCD_MAX_CHARS
#define LCD_MAX_CHARS 20
#endif
#ifndef LCD_MAX_LINES
#define LCD_MAX_LINES 4
#endif
#ifndef LCD_ADDRESS
#define LCD_ADDRESS 0x38
#endif

class cDisplay
  {
  public:
    cDisplay();
    void Init();
    void setBacklight(int);
    eWorkmodes selectMode();
    void clear(void);
    void clearLine(int line);
    void printLine(int line, int pos, const char* text);
  private:
    std::unique_ptr<LCD_I2C> display;
  };
#endif
