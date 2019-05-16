#include "tm4c123GH6pm.h"
#include "MCAL.h"
#include <stdint.h>


void UART_Write(unsigned char data){
  while((UART1_FR_R&UART_FR_TXFF) != 0);
  UART1_DR_R = data;
}
