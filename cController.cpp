#include "cController.hpp"
#include <cstdlib>

cController::cController() {
  Heater = std::make_unique<cHeaterRelay>();
  LCD    = std::make_unique<cDisplay>();
  thermometer    = std::make_unique<cDS18B20>();
  }


cController::~cController() {

  }


bool
cController::Init() {
//  LCD->Init();
//  Heater->Start();
  thermometer->Init();
  return true;
  }


int
cController::Run() {

  return EXIT_SUCCESS;
  }
