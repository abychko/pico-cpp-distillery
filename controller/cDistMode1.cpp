#include <cDistMode1.hpp>
#include <cstdio>

cDistMode1::cDistMode1() {
  stopTemp = 100.0;
  currentTemp = mDS18B20->getTemp();
  }


void
cDistMode1::Start() {
  mStatus = eRUNNING;
  gpio_put(HEATER_PIN, _on);
  lcd_display->clear();
  lcd_display->printLine(0, 0, DIST1MODE);
  fillDisplayFields();
  while(currentTemp < stopTemp) {
    updateTemp();
    updatePower();
    updateStatus();
#ifdef DEBUG
    printValues();
#endif
    }
  gpio_put(HEATER_PIN, _off);
  mStatus = eSUCCESS;
  updateStatus();
  }
