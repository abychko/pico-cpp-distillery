
set(DISPLAY_SOURCES
  cDisplay.cpp
  LCD_I2C.cpp
  )

add_library(hd_display
  STATIC
  ${DISPLAY_SOURCES}
  )

target_compile_definitions(hd_display
  PRIVATE
  LCD_SDA_PIN=${LCD_SDA_PIN} LCD_SCL_PIN=${LCD_SCL_PIN}
  LCD_MAX_CHARS=${LCD_MAX_CHARS} LCD_MAX_LINES=${LCD_MAX_LINES}
  LCD_ADDRESS=${LCD_ADDRESS}
  I2C_SPEED=${I2C_SPEED}
)

target_link_libraries(hd_display
  hardware_i2c
  pico_stdlib
  )
