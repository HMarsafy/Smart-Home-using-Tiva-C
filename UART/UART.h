#ifndef UART_HEADER
#define UART_HEADER

#include "MCAL.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

void UART_init(void);
uint8_t UART_Read(void);
void UART_Write(uint8_t data);
#endif
