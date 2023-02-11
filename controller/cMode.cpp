#include <cMode.hpp>
#include <cstdio>

cMode::cMode() {
  stopTemp = 0;
  currentTemp = 0;
  mDS18B20    = std::make_unique<cDS18B20>();
  }


#ifdef DEBUG
void
cMode::printValues() {
  printf("Temperature: %.2f\n", currentTemp);
  }
#endif

void
cMode::setDisplay(std::shared_ptr<cDisplay> _display) {
  lcd_display = _display;
  }
