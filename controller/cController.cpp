//
#include <cstdio>
//
#include "cController.hpp"
#include <eWorkmodes.hpp>
#include <cDistMode1.hpp>
#include <cDistMode2.hpp>
//

cController::cController() {
  mDisplay    = std::make_unique<cDisplay>();
  mMode = NULL;
  }


cController::~cController() {

  }


bool
cController::Init() {
//  mDisplay->Init();

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
      mMode = std::make_unique<cDistMode1>();
      break;
    case eDistillation2:
      mMode = std::make_unique<cDistMode2>();
      break;
    default:
      break;
    }
  if(mMode) {
    mMode->Start();
    }
  }
