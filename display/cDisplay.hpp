#ifndef __cDisplay_hpp__
#define __cDisplay_hpp__

#include "hardware/i2c.h"
#include "LCD_I2C.hpp"
#include <memory>
#include <eWorkmodes.hpp>

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
    ~cDisplay();
    void Init();
    eWorkmodes selectMode();
  private:
    std::unique_ptr<LCD_I2C> display;
  };
#endif
