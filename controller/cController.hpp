#ifndef __cController_hpp__
#define __cController_hpp__
//
#include <memory>
//
#include <cDisplay.hpp>

#include <cDistMode1.hpp>
#include <cDistMode2.hpp>
//

class cController
  {
  public:
    cController();
    ~cController();
    bool Init();
    void Run();
  private:
    std::unique_ptr<cDisplay>       mDisplay;
    std::unique_ptr<cMode>          mMode;
  };
#endif
