#ifndef __cController_hpp__
#define __cController_hpp__
//
#include <memory>
//
#include <cDisplay.hpp>
#include <cMode.hpp>
//

class cController
  {
  public:
    cController();
    void Run();
    void turnOnLED();
  private:
    std::unique_ptr<cDisplay> mDisplay;
    std::unique_ptr<cMode>    mMode;
  };
#endif
