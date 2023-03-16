set(EM_SOURCES
  cEnergyMon.cpp
  )

add_library(hd_em
  STATIC
  ${EM_SOURCES}
  )

target_compile_definitions(hd_em
  PRIVATE
  UART_TX_PIN=${UART_TX_PIN}
  UART_RX_PIN=${UART_RX_PIN}
  UART_ID=${UART_ID}
  UART_BAUD_RATE=${UART_BAUD_RATE}
  UART_PARITY=${UART_PARITY}
  UART_DATA_BITS=${UART_DATA_BITS}
  UART_STOP_BITS=${UART_STOP_BITS}
  )

target_link_libraries(hd_em
  pico_stdlib
  )
