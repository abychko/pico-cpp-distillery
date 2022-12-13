#ifndef __cController_hpp__
#define __cController_hpp__

#include <hardware/i2c.h>
#include <cDisplay.hpp>
#include "cHeaterRelay.hpp"
#include <cDS18B20.hpp>
#include <memory>
#include <vector>

class cController
  {
  public:
    cController();
    ~cController();
    bool Init();
    int Run();
  private:
    std::unique_ptr<cHeaterRelay>   Heater;
    std::unique_ptr<cDisplay>       LCD;
    std::unique_ptr<cDS18B20>       thermometer;

  };
#endif
