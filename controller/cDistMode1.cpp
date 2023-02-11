#include <cDistMode1.hpp>
#include <cstdio>

cDistMode1::cDistMode1() {
  stopTemp = 100.0;
  currentTemp = mDS18B20->getTemp();
  }


void
cDistMode1::Start() {
  gpio_put(HEATER_PIN, _on);
  lcd_display->clear();
  lcd_display->printLine(0, 0, DIST1MODE);

  char temp[6];

  while(currentTemp < stopTemp) {
    currentTemp = mDS18B20->getTemp();
    lcd_display->printLine(1, 0, TEMP);
    memset(temp, 0, sizeof(temp));
    sprintf(temp, "%.2f", currentTemp);
    lcd_display->printLine(1, sizeof(TEMP), temp);
#ifdef DEBUG
    printValues();
#endif
    }
  gpio_put(HEATER_PIN, _off);
  lcd_display->clear();
  lcd_display->printLine(0, 0, DIST1MODE);
  }
