#ifndef __cMode_hpp__
#define __cMode_hpp__

#include "pico/float.h"
#include <cDS18B20.hpp>

constexpr uint _on  = 1;
constexpr uint _off = 0;

class cMode
  {
  public:
    cMode();
    virtual void Start() = 0;

  protected:
    std::unique_ptr<cDS18B20>       mDS18B20;
    float stopTemp;
    float currentTemp;
  };
#endif
