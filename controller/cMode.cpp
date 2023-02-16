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
cMode::fillDisplayFields() {
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
  char _power[] = "230V 13A 3000W";
  lcd_display->printLine(1, sizeof(ELECTRICITY), _power);
  }

float
cMode::getAlcohol(const std::map<float, float>& map) {
  if (mStatus != eRUNNING) { return 0; }
  if ( (currentTemp > maxTemp) || (currentTemp < minTemp) ) { return 0; }
  auto _val = map.find(currentTemp);
  if(_val != map.end()) { return _val->second; }
  return map.lower_bound(currentTemp)->second;
}

void
cMode::updateAlcConcentration(const std::map<float, float>& map) {
  float alc_percentage = getAlcohol(map);
  char buffer[6];
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "\xDA%05.2f%%", alc_percentage);
  lcd_display->printLine(2, sizeof(TEMP)+7 , buffer);
}

void
cMode::updateStatus() {
  switch(mStatus) {
    case eRUNNING:
      lcd_display->printLine(3, sizeof(STATUS), RUNNINGSTR);
      break;
    case eFINISHING:
      lcd_display->printLine(3, sizeof(STATUS), FINISHING);
      break;
    case eSUCCESS:
      lcd_display->printLine(3, sizeof(STATUS), FINISHED);
      break;
    default:
      lcd_display->printLine(3, sizeof(STATUS), "N/A");
      break;
    }
  }


void
cMode::Start() {
  gpio_put(HEATER_PIN, _on);
  mStatus = eRUNNING;
  lcd_display->clear();
  fillDisplayFields();
  }


#ifdef COOLING_VALVE
void
cMode::turnOffCooling() {

  }
#endif

void
cMode::Stop() {
  gpio_put(HEATER_PIN, _off);
#ifdef COOLING_VALVE
  if (mStatus == eRUNNING) {mStatus = eFINISHING;}
  updateStatus();
  for(int i=0; i<120; i++) {
    if(currentTemp < 50.0) {break;}
    sleep_ms(500);
    updatePower();
    updateTemp();
    }
  turnOffCooling();
#endif
  mStatus = eSUCCESS;
  updateStatus();
//  lcd_display->setBacklight(_off);
  while(true) {
    updatePower();
    updateTemp();
    }
  }
