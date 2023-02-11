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
cController::turnOnLED() {
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_put(LED_PIN, _on);
  }


void
cController::Run() {
  turnOnLED();
  mDisplay->Init();
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
    mMode->setDisplay(mDisplay);
    mMode->Start();
    }
  }
