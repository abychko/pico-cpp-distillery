#ifndef __cHeaterRelay_hpp__
#define __cHeaterRelay_hpp__

#include "cRelay.hpp"
#include "cCurrentSensor.hpp"

#include <memory>

#include <math.h>
#include <pico/float.h>
#include "pico/types.h"
#include "pico/bootrom/sf_table.h"

#ifndef HEATER_PIN
#define HEATER_PIN 13
#endif
#ifndef HEATING_POWER_MAX
#define HEATING_POWER_MAX 3000
#endif
#ifndef HEATING_POWER
#define HEATING_POWER 1000
#endif
#ifndef AC_VOLTAGE
#define AC_VOLTAGE 220
#endif
#ifndef AC_FREQUENCY
#define AC_FREQUENCY 50
#endif

// Calculated values
uint constexpr HALF_CYCLE = (AC_FREQUENCY * 2);
/* 1000ms / 100 = 10ms */
uint constexpr HALF_CYCLE_TIME = (1000/HALF_CYCLE);

class cHeaterRelay : public cRelay
  {
  public:
    cHeaterRelay();
    ~cHeaterRelay();
    void Start();
    float getCurrent();

  private:
    std::unique_ptr<cCurrentSensor> AmpMeter;
  };
#endif
