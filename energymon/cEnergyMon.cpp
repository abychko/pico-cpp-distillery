#include <cEnergyMon.hpp>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <cstdio>
#include <cstring>

cEnergyMon::cEnergyMon() {
  uart_init(UART_ID, UART_BAUD_RATE);
  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
  uart_set_hw_flow(UART_ID, false, false);
  uart_set_format(UART_ID, UART_DATA_BITS, UART_STOP_BITS, UART_PARITY);
  }


uint8_t REQ_DATA[] = { 0xF8, 0x04, 0x00, 0x00, 0x00, 0x0A, 0x64, 0x64 };

void
cEnergyMon::readMeasures() {
  if(uart_is_readable(UART_ID)) {
    mPowerMetrics.clear();
#ifdef DEBUG
    printf("Res: ");
#endif
    while (uart_is_readable(UART_ID)) {
      uint8_t _byte = uart_getc(UART_ID);
      mPowerMetrics.push_back(_byte);
#ifdef DEBUG
      printf("0x%.2X + ", _byte);
      }
    printf("\n");
#else
      }
#endif
    }
  }

void
cEnergyMon::requestMetrics() {
  if (uart_is_writable) {
    for(int i=0; i<sizeof(REQ_DATA); i++) {
      uart_putc(UART_ID, REQ_DATA[i]);
//printf("0x%.2X ", REQ_DATA[i]);
      }
// printf("\n");
    sleep_ms(100);
    readMeasures();
    }
  }


bool
cEnergyMon::checkResult() {
  switch(mPowerMetrics[1]) {
    case 0x04:
      return true;
    case 0x84:
      printf("Error 0x%X\n", mPowerMetrics[2]);
      break;
    default:
      printf("Unknown error!\n");
      break;
    }
  return false;
  }


float
cEnergyMon::getVoltage() {
  if(!checkResult()) {
    return -1.0;
    }
  return ((mPowerMetrics[3] << 8) + mPowerMetrics[4]) / 10.0;
  }


float
cEnergyMon::getCurrent() {
  if(!checkResult()) {
    return -1.0;
    }
//printf("Amp: %.3f\n", ((mPowerMetrics[5] << 8) + mPowerMetrics[6]) / 1000.0);
  return ((mPowerMetrics[5] << 8) + mPowerMetrics[6]) / 1000.0;
  }


float
cEnergyMon::getPower() {
  if(!checkResult()) {
    return -1.0;
    }
  return ((mPowerMetrics[9] << 8) + mPowerMetrics[10]) / 10.0;
  }
