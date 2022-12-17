//
#include <cstdio>
//
#include "cController.hpp"
#include <eWorkmodes.hpp>
#include <cDistMode1.hpp>
#include <cDistMode2.hpp>
//

cController::cController() {
  mHeater = std::make_unique<cHeaterRelay>();
  mDisplay    = std::make_unique<cDisplay>();
  mDS18B20    = std::make_unique<cDS18B20>();
  }


cController::~cController() {

  }


bool
cController::Init() {
//  mDisplay->Init();
//  Heater->Init();
//  thermometer->Init();
/*
  if (!Heater->Init()){
    auto err = Heater->getStatus();
    shutdownSystem(err);
  }
*/
  return true;
  }


/*
  while (true) {
    printf("Temperature: %3.2f\n", mDS18B20->getTemp());
    }
*/

void
cController::Run() {
  auto mode = mDisplay->selectMode();
  switch (mode) {
    case eDistillation1:
      break;
    case eDistillation2:
      break;
    default:
      break;
    }
  }
