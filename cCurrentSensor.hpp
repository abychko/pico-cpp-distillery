#ifndef __cCurrentSensor_hpp__
#define __cCurrentSensor_hpp__

#include <math.h>
#include <pico/float.h>
#include "pico/types.h"
#include "pico/bootrom/sf_table.h"
#include "hardware/adc.h"

float constexpr conversion_factor = 3.3f / (1 << 12);

class cCurrentSensor
  {

  public:
    cCurrentSensor();
    float getRawValue();

  };
#endif
