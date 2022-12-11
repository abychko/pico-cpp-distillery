#include "cController.hpp"
#include <cstdlib>

cController::cController() {
  Heater = std::make_unique<cHeaterRelay>();
  LCD    = std::make_unique<cDisplay>();
  }


cController::~cController() {

  }


bool
cController::Init() {
//  LCD->Init();
  Heater->Start();
  return true;
  }


int
cController::Run() {

  return EXIT_SUCCESS;
  }
