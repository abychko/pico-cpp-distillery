

set(HEATER_SOURCES
  cHeaterRelay.cpp
  )

add_library(hd_heater
  STATIC
  ${HEATER_SOURCES}
  )

target_compile_definitions(hd_heater
  PRIVATE
  HEATER_MODE_BRESENHAM # set it to HEATER_MODE_PHASE for SSR LA relays
  HEATER_PIN=${HEATER_PIN}
  HEATING_POWER_MAX=${HEATING_POWER_MAX}  # max heater power in Watts
  HEATING_POWER=${HEATING_POWER}      # heater power in normal mode
  AC_VOLTAGE=${AC_VOLTAGE}
  AC_FREQUENCY=${AC_FREQUENCY}
  )

target_link_libraries(hd_heater
  pico_stdlib
  )
