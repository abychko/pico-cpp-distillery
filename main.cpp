#include <memory>
#include <cstdlib>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "cController.hpp"

int
main(void) {

  stdio_init_all();

  std::unique_ptr<cController> cCtl = std::make_unique<cController>();
  cCtl->Run();

  return EXIT_SUCCESS;
  }
