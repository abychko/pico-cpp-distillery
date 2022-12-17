#include <cMode.hpp>

cMode::cMode() {
  stopTemp = 0;
  currentTemp = 0;
  mDS18B20    = std::make_unique<cDS18B20>();
  }
