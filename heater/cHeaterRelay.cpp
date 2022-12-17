#include "cHeaterRelay.hpp"
#include <cstdio>

cHeaterRelay::cHeaterRelay() {
  _power = 0;
  _can_run = false;
  gpio_init(HEATER_PIN);
  gpio_set_dir(HEATER_PIN, GPIO_OUT);

//  AmpMeter = std::make_unique<cCurrentSensor>();

  }


cHeaterRelay::~cHeaterRelay() {

  }


/*
float
cHeaterRelay::getCurrent() {
  float amp = 0;

  return amp;
  }
*/
void
cHeaterRelay::setPower(uint power) {
  _power = power;
  }


void
cHeaterRelay::StartBresenham() {
  int error = 0;
  int value = 0;
  int flag = 0;

  int volts = 230;
  float amp_diff = ((float)HEATING_POWER / (float)volts) - ((float)HEATING_POWER / (float)AC_VOLTAGE);
  int watt_diff = float2int(amp_diff * (float)volts);

  sleep_ms(7000);

  printf("amp_diff = %.6f\n", amp_diff);
  printf("watt_diff = %d\n", watt_diff);

/* initial speed heating */
// gpio_put(HEATER_PIN, 1);

  while(true) {
    error += watt_diff;
    value = (HEATING_POWER + error);
    if (value < HEATING_POWER) {
      error = value;
      flag = 0;
      }
    else {
      error = (value - HEATING_POWER_MAX);
      flag = 1;
      }
    gpio_put(HEATER_PIN, flag);
    sleep_ms(HALF_CYCLE_TIME);
    }                                             // while(true)
  }
