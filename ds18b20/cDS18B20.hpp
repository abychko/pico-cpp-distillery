#ifndef __cDS18B20_cpp__
#define __cDS18B20_cpp__

#include "onewire.h"
#include <memory>

#ifndef ONEWIRE_PIN
#define ONEWIRE_PIN 15
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
  };
#endif
