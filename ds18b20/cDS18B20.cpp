#include "cDS18B20.hpp"
#include <cstdio>
#include <cmath>

cDS18B20::cDS18B20() {
  OneWire = std::make_unique<One_wire>(ONEWIRE_PIN);
  }


bool
cDS18B20::Init() {
  OneWire->init();
  return OneWire->set_resolution(address, 12);
  }


float
cDS18B20::getTemp() {
  OneWire->single_device_read_rom(address);
  OneWire->convert_temperature(address, true, false);
  return OneWire->temperature(address);
  }
