#include <cMode.hpp>

cMode::cMode() {
  mDS18B20    = std::make_unique<cDS18B20>();
  mHeater = std::make_unique<cHeaterRelay>();
  }


bool
cMode::Init() {
/*
  if (!Heater->Init()){
    auto err = Heater->getStatus();
    shutdownSystem(err);
  }
*/
  return true;
  }
