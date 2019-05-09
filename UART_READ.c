#include "tm4c123gh6pm.h"
#include "stdint.h"
uint8_t UART_READ(void)
{
	while(UART0_FR_R &(0x0010!=0));
	return ((UART0_DR_R&0xFF);
}
