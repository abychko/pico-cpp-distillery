#ifndef __cDS18B20_cpp__
#define __cDS18B20_cpp__

#include <onewire.h>
#include <memory>
#include <deque>
#include "pico/float.h"

#ifndef ONEWIRE_PIN
#define ONEWIRE_PIN 15
#endif

#ifndef t_vector_size
#define t_vector_size 4
#endif

#ifndef SENSOR_RES
#define SENSOR_RES 12
#endif

class cDS18B20
  {
  public:
    cDS18B20();
    float getTemp();
    bool Init();
  private:
    std::unique_ptr<One_wire> OneWire;
    rom_address_t address{};
    std::deque<float> _t_values;
  };
#endif
