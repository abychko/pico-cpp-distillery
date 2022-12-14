//
#include <cstdio>
//
#include "cController.hpp"
#include <eWorkmodes.hpp>
#include <cDistMode1.hpp>
#include <cDistMode2.hpp>
#include <cRectMode1.hpp>
#include <cRectMode2.hpp>
//

cController::cController() {
  mDisplay    = std::make_unique<cDisplay>();
  mMode = NULL;
  }


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
    case eRectification1:
      mMode = std::make_unique<cRectMode1>();
      break;
    case eRectification2:
      mMode = std::make_unique<cRectMode2>();
      break;
    default:
      break;
    }
  if(mMode) {
    mMode->Start();
    }
  }
