# Copyright Alexey Bychko 2023
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD "pico")
set(PROG_VERSION "0.1")

set(PICO_DEFAULT_FLOAT_IMPL pico_float_pico)
set(PICO_DEFAULT_DOUBLE_IMPL pico_double_pico)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(
  HomeDistillery
  VERSION ${PROG_VERSION}
  DESCRIPTION "Pico-based controller for home distillery/brewery"
  LANGUAGES ASM C CXX
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# hardware configuration and connected pins
add_compile_definitions(${PROJECT_NAME}-${PROG_VERSION}
  PRIVATE
  PICO_FLOAT_SUPPORT_ROM_V1=0 PICO_DOUBLE_SUPPORT_ROM_V1=0
  LANG_RUSSIAN # comment/delete to have English messages
  HEATER_PIN=13
  HEATER_MODE_BRESENHAM # set it to HEATER_MODE_PHASE for SSR LA relays
  HEATING_POWER_MAX=3000  # max heater power in Watts
  HEATING_POWER=1000      # heater power in normal mode
  AC_VOLTAGE=220
  AC_FREQUENCY=50
  LCD_SDA_PIN=4 LCD_SCL_PIN=5
  LCD_MAX_CHARS=20 LCD_MAX_LINES=4
  LCD_ADDRESS=0x38
  I2C_SPEED=100000
)
#
pico_sdk_init()
#
include_directories(onewire)
include_directories(display)
#
add_subdirectory(onewire)
add_subdirectory(display)
#
set(SOURCES
    main.cpp
    cController.cpp
    cCurrentSensor.cpp
    cHeaterRelay.cpp
    cRelay.cpp
    )
#
add_executable(${PROJECT_NAME}-${PROG_VERSION} ${SOURCES})
#
pico_set_program_name(${PROJECT_NAME}-${PROG_VERSION} "${PROJECT_NAME}")
pico_set_program_version(${PROJECT_NAME}-${PROG_VERSION} "${PROG_VERSION}")
pico_enable_stdio_usb(${PROJECT_NAME}-${PROG_VERSION} 1)
pico_enable_stdio_uart(${PROJECT_NAME}-${PROG_VERSION} 0)
#
# TODO
# Load uf2 to RAM instead of flash
pico_set_binary_type(${PROJECT_NAME}-${PROG_VERSION} no_flash)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#  set(CMAKE_VERBOSE_MAKEFILE ON)
  set(PICO_DEOPTIMIZED_DEBUG ON)
  add_compile_options(-Wall -Wextra)
  add_compile_definitions(DEBUG)
endif()


target_link_libraries(${PROJECT_NAME}-${PROG_VERSION}
  pico_stdlib
  hardware_i2c
  hardware_adc
  pico_onewire
  pico_display
)
pico_add_extra_outputs(${PROJECT_NAME}-${PROG_VERSION})
