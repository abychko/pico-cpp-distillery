#include <memory>
#include <cstdlib>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "cController.hpp"

int
main(void) {

  stdio_init_all();

  std::shared_ptr<cController> ctl = std::make_shared<cController>();

  if (! ctl->Init()) {
    return EXIT_FAILURE;
    }

  ctl->Run();

  return EXIT_SUCCESS;
  }
