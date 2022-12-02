#ifndef __cRelay_hpp__
#define __cRelay_hpp__
#include "pico/stdlib.h"

class cRelay
  {
  public:
    virtual ~cRelay();
  protected:
    uint relayPin;
  };
#endif
