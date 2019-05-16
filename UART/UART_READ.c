#include "tm4c123GH6pm.h"
#include "MCAL.h"
#include <stdint.h>


// Wait for new input, then return ASCII code
unsigned char UART_Read(void){
  while((UART1_FR_R&UART_FR_RXFE) != 0);
  return((unsigned char)(UART1_DR_R&0xFF));
}
