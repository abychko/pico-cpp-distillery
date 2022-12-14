
set(CONTROLLER_SOURCES
  cController.cpp
  )

add_library(hd_controller
  STATIC
  ${CONTROLLER_SOURCES}
  )

#target_compile_definitions(hd_controller
#  PRIVATE
#)

target_link_libraries(hd_controller
  hardware_i2c
  pico_stdlib
  hd_ds18b20
  hd_display
  hd_heater
  )
