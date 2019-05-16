#include "tm4c123GH6pm.h"
#include "MCAL.h"
#include <stdint.h>
#include "lcd.h"


void UART_init(void){
	uint16_t delay;
  SYSCTL_RCGCUART_R |= SYSCTL_RCGC1_UART1; // activate UART1
  delay = SYSCTL_RCGCUART_R;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;  //enable clock
	delay = SYSCTL_RCGCGPIO_R;        		  //delay		
	GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;   	  //unlock
	GPIO_PORTC_CR_R |= 0x30;	
	UART1_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART1_IBRD_R = 27;                    // IBRD = int(50,000,000 / (16 * 115,200)) = int(27.1267)
  UART1_FBRD_R = 8;                     // FBRD = int(0.1267 * 64 + 0.5) = 8
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
	UART1_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART1_CTL_R |= UART_CTL_UARTEN;       // enable UART
  GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTC_AFSEL_R |= 0x30;           // enable alt funct on PA1-0
  GPIO_PORTC_DEN_R |= 0x30;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00220000;
  GPIO_PORTC_AMSEL_R &= ~0x30;          // disable analog functionality on PA
}
