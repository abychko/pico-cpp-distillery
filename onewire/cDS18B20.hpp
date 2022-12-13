#ifndef __cDS18B20_cpp__
#define __cDS18B20_cpp__

#include "onewire.h"

#ifndef ONEWIRE_PIN
  #define ONEWIRE_PIN 15
#endif


class cDS18B20
  {
  public:
    float getTemp();
    bool Init();

  };
#endif
