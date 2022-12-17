#include <memory>
#include <cstdlib>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "cController.hpp"

int
main(void) {

  stdio_init_all();

  std::unique_ptr<cController> ctl = std::make_unique<cController>();

  if (! ctl->Init()) {
    return EXIT_FAILURE;
    }

  ctl->Run();

  return EXIT_SUCCESS;
  }
