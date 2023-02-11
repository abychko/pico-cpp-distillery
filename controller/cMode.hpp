#ifndef __cMode_hpp__
#define __cMode_hpp__

#include "pico/float.h"
#include <cDS18B20.hpp>
#include <cDisplay.hpp>
#include <memory>

constexpr uint _on  = 1;
constexpr uint _off = 0;

class cMode
  {
  public:
    cMode();
    virtual void Start() = 0;
    void setDisplay(std::shared_ptr<cDisplay> _display);
#ifdef DEBUG
    void printValues();
#endif

  protected:
    std::unique_ptr<cDS18B20>       mDS18B20;
    float stopTemp;
    float currentTemp;
    std::shared_ptr<cDisplay> lcd_display;
  };
#endif
