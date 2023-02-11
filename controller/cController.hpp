#ifndef __cController_hpp__
#define __cController_hpp__
//
#include <memory>
//
#include <cMode.hpp>
//
class cController
  {
  public:
    cController();
    void Run();
    void turnOnLED();
  private:
    std::unique_ptr<cMode>    mMode;
    std::shared_ptr<cDisplay> mDisplay;
  };
#endif
