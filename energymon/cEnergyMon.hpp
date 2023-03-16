#ifndef __cEnergy_Monitor_hpp__
#define __cEnergy_Monitor_hpp__

#include "pico/float.h"
#include <vector>

/*
  0xF8 is used as the general address
  (The address range of the slave is 0x01-0xF7)
*/

class cEnergyMon
  {
  public:
    cEnergyMon();
    void requestMetrics();
    float getVoltage();
    float getCurrent();
    float getPower();
  private:
    void readMeasures();
    bool checkResult();
    std::vector<int> mPowerMetrics;

  };
#endif
