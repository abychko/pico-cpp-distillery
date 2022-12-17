#include <cDistMode1.hpp>

cDistMode1::cDistMode1() {
  stopTemp = 100.0;
  currentTemp = mDS18B20->getTemp();
  }


void
cDistMode1::Start() {
  gpio_put(HEATER_PIN, _on);
  while(currentTemp <= stopTemp) {
    sleep_ms(500);
    currentTemp = mDS18B20->getTemp();
    }
  gpio_put(HEATER_PIN, _off);
  }
