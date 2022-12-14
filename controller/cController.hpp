#ifndef __cController_hpp__
#define __cController_hpp__

#include <cDisplay.hpp>
#include "cHeaterRelay.hpp"
#include <cDS18B20.hpp>
#include <memory>

class cController
  {
  public:
    cController();
    ~cController();
    bool Init();
    void Run();
  private:
    std::unique_ptr<cHeaterRelay>   Heater;
    std::unique_ptr<cDisplay>       LCD;
    std::unique_ptr<cDS18B20>       thermometer;
  };
#endif
