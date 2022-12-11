SET(${ONEWIRE_SOURCES} 
  ${CMAKE_CURRENT_LIST_DIR}/onewire.cpp
  )

add_library(pico_onewire 
  STATIC
  ${ONEWIRE_SOURCES}
  )

target_link_libraries(pico_onewire 
  pico_stdlib 
  hardware_gpio
  )

