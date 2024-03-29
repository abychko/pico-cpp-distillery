#include <cDistMode1.hpp>
#include <cstdio>

cDistMode1::cDistMode1() {
  stopTemp = 98.0;
  currentTemp = 0;                                // mDS18B20->getTemp();
  }


void
cDistMode1::Start() {
  cMode::Start();
  cMode::lcd_display->printLine(0, 0, DIST1MODE);
  while(currentTemp < stopTemp) {
//  updateTemp();
    updatePower();
    updateStatus();
    updateAlcConcentration(vapour);
    if(mStatus != eRUNNING) {                     //check for hardware errors
      return;
      }
#ifdef DEBUG
    printValues();
#endif
    }
  }
