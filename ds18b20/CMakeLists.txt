
SET(ONEWIRE_SOURCES
  onewire.cpp
  cDS18B20.cpp
  )

add_library(hd_ds18b20
  STATIC
  ${ONEWIRE_SOURCES}
  )

target_compile_definitions(hd_ds18b20
  PRIVATE
  ONEWIRE_PIN=${ONEWIRE_PIN}
  )

target_link_libraries(hd_ds18b20
  pico_stdlib 
  hardware_gpio
  )

