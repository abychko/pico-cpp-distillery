#ifndef __cMode_hpp__
#define __cMode_hpp__

#include "pico/float.h"
#include "cHeaterRelay.hpp"
#include <cDS18B20.hpp>

// stop speed heating at stopTemp
constexpr
float stopTemp = 60.0;

class cMode
  {
  public:
    cMode();
    virtual void Start() = 0;
    bool Init();
  protected:
    std::unique_ptr<cHeaterRelay>   mHeater;
    std::unique_ptr<cDS18B20>       mDS18B20;
  };
#endif
