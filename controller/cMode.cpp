#include <cMode.hpp>
#include <cstdio>

cMode::cMode() {
  stopTemp = 0;
  currentTemp = 0;
  mDS18B20    = std::make_unique<cDS18B20>();
  mStatus = eSUCCESS;
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

void
cMode::fillDisplayFields(){
  lcd_display->printLine(2, 0, TEMP);
  lcd_display->printLine(1, 0, ELECTRICITY);
  lcd_display->printLine(3, 0, STATUS);
}


void
cMode::updateTemp() {
  char temp[6];
  currentTemp = mDS18B20->getTemp();
  memset(temp, 0, sizeof(temp));
  sprintf(temp, "%.2f ", currentTemp);
  lcd_display->printLine(2, sizeof(TEMP), temp);
  }

void
cMode::updatePower() {

}

void
cMode::updateStatus() {
  switch(mStatus) {
    case eRUNNING:
      lcd_display->printLine(3, sizeof(STATUS), RUNNINGSTR);
      break;
    case eSUCCESS:
      lcd_display->printLine(3, sizeof(STATUS), COMPLETED_SUCCESSFULLY);
      break;
    default:
      lcd_display->printLine(3, sizeof(STATUS), "N/A");
      break;
  }
}

void
cMode::Stop() {
  updateStatus();
  while(true) {
    updateTemp();
    }
  }
