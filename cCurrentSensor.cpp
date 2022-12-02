#include "cCurrentSensor.hpp"

cCurrentSensor::cCurrentSensor() {
  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  }


float cCurrentSensor::getRawValue() {
  uint16_t res = adc_read();
  float volts = res * conversion_factor;
  return volts;
  }
