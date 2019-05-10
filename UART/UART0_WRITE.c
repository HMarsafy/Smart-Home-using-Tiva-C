#include "tm4c123gh6pm.h"
#include "UART.h"
#include "stdint.h"

void UART0_WRITE(uint8_t data){
	
	while ((UART0_FR_R&UART_FR_TXFF)!=0);  // AS LONG AS THE FIFO IS FULL -->DO NOTHING 
	
	UART0_DR_R = data;
	
}
