# Copyright Alexey Bychko 2023
cmake_minimum_required(VERSION 3.10)
#
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#
set(PICO_BOARD "pico")
set(PROG_VERSION "0.1")
#
set(PICO_DEFAULT_FLOAT_IMPL pico_float_pico)
set(PICO_DEFAULT_DOUBLE_IMPL pico_double_pico)
#
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
#
project(
  SmartDistillery
  VERSION ${PROG_VERSION}
  DESCRIPTION "Pico-based controller for home distillery/brewery"
  LANGUAGES ASM C CXX
)
#
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
# delete it to have English messages
add_definitions(-DLANG_RUSSIAN)
#
# hardware configuration and connected pins
set(LCD_SDA_PIN 4)
set(LCD_SCL_PIN 5)
set(LCD_MAX_CHARS 20)
set(LCD_MAX_LINES 4)
set(LCD_ADDRESS 0x38)
#
set(I2C_SPEED 100000)
#
set(HEATER_PIN 12)
set(HEATING_POWER_MAX 3000)  # max heating power in Watts
set(HEATING_POWER 1500)      # normal heating power
set(AC_VOLTAGE 220)          # actually it's RMS, please note
set(AC_FREQUENCY 50)
#
set(ONEWIRE_PIN 15) # for DS18B20 temperature sensor
#
set(UART_TX_PIN 0) # UART default TX PIN
set(UART_RX_PIN 1) # UART default RX PIN
set(UART_ID uart0)
# from datasheet
set(UART_BAUD_RATE 9600)
set(UART_DATA_BITS 8)
set(UART_STOP_BITS 1)
set(UART_PARITY UART_PARITY_NONE)
#
set(COOLING_VALVE OFF)
#
if(COOLING_VALVE)
  add_definitions(-DCOOLING_VALVE)
endif()
#
pico_sdk_init()
#
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(controller)
include_directories(display)
include_directories(ds18b20)
include_directories(heater)
include_directories(energymon)
#
add_subdirectory(controller)
add_subdirectory(display)
add_subdirectory(ds18b20)
add_subdirectory(heater)
add_subdirectory(energymon)
#
set(SOURCES
    main.cpp
    cCurrentSensor.cpp
    cRelay.cpp
    )
#
add_executable(${PROJECT_NAME}-${PROG_VERSION} ${SOURCES})
#
pico_set_program_name(${PROJECT_NAME}-${PROG_VERSION} ${PROJECT_NAME})
pico_set_program_version(${PROJECT_NAME}-${PROG_VERSION} ${PROG_VERSION})
pico_enable_stdio_usb(${PROJECT_NAME}-${PROG_VERSION} 1)
pico_enable_stdio_uart(${PROJECT_NAME}-${PROG_VERSION} 0)
#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG)
  set(CMAKE_VERBOSE_MAKEFILE ON)
  set(PICO_DEOPTIMIZED_DEBUG 1)
  # Load uf2 to RAM instead of flash
  pico_set_binary_type(${PROJECT_NAME}-${PROG_VERSION} no_flash)
endif()
#
target_link_libraries(${PROJECT_NAME}-${PROG_VERSION}
  pico_stdlib
  hardware_adc
  hd_controller
)
#
pico_add_extra_outputs(${PROJECT_NAME}-${PROG_VERSION})
#
