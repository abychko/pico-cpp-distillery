#include "cDS18B20.hpp"
#include <cstdio>
#include <cmath>

cDS18B20::cDS18B20() {
  _t_values.clear();
  OneWire = std::make_unique<One_wire>(ONEWIRE_PIN);
  }


bool
cDS18B20::Init() {
  OneWire->init();
  return OneWire->set_resolution(address, SENSOR_RES);
  }


float
cDS18B20::getTemp() {
  OneWire->single_device_read_rom(address);
  OneWire->convert_temperature(address, true, false);
  float _val = OneWire->temperature(address);
  _t_values.push_back(_val);

// leave only t_vector_size latest values
  while(_t_values.size() > t_vector_size) {
    _t_values.pop_front();
    }

  float _sum = 0;
  for (auto it = _t_values.cbegin(); it != _t_values.cend(); it++) {
    _sum += *it;
#ifdef DEBUG
    printf("In _t_values vector: %.2f\n", *it);
#endif
    }
  return _sum/_t_values.size();
// a hack to round float value to %.2f
//  return std::roundf(_sum/_t_values.size() * 100) / 100;
  }
