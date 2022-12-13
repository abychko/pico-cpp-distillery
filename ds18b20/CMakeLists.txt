
if(NOT ONEWIRE_PIN)
  set(ONEWIRE_PIN 15)
endif()

SET(ONEWIRE_SOURCES
  onewire.cpp
  cDS18B20.cpp
  )

add_library(pico_ds18b20
  STATIC
  ${ONEWIRE_SOURCES}
  )

target_compile_definitions(pico_ds18b20
  PRIVATE
  ONEWIRE_PIN=${ONEWIRE_PIN}
  )

target_link_libraries(pico_ds18b20
  pico_stdlib 
  hardware_gpio
  )

