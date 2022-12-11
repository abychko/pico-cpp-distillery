set(DISPLAY_SOURCES
  cDisplay.cpp
  LCD_I2C.cpp
  )

add_library(pico_display
  STATIC
  ${DISPLAY_SOURCES}
  )

target_link_libraries(
  pico_display
  hardware_i2c
  pico_stdlib
  )
