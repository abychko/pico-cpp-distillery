#include <cDistMode1.hpp>
#include <cstdio>

cDistMode1::cDistMode1() {
  stopTemp = 100.0;
  currentTemp = mDS18B20->getTemp();
  }


void
cDistMode1::Start() {
  cMode::Start();
  cMode::lcd_display->printLine(0, 0, DIST1MODE);
  while(currentTemp < stopTemp) {
    updateTemp();
    updatePower();
    updateStatus();
    if(mStatus != eRUNNING) {return;}
#ifdef DEBUG
    printValues();
#endif
    }
  }
