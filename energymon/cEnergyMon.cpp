#include <cEnergyMon.hpp>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/float.h"

cEnergyMon::cEnergyMon(){
  uart_init(UART_ID, UART_BAUD_RATE);
  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
  int __unused rate = uart_set_baudrate(UART_ID, UART_BAUD_RATE);
  //uart_set_hw_flow(UART_ID, false, false); // ?
  uart_set_format(UART_ID, UART_DATA_BITS, UART_STOP_BITS, UART_PARITY);
  // uart_set_fifo_enabled(UART_ID, false); // ?
}

