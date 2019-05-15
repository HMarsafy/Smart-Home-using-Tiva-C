#include "tm4c123gh6pm_custom.h"
#include "MCAL.h"
#include <stdint.h>


void Port_Init(uint8_t port_index, uint8_t pins_mask, uint32_t GPIO_PCTL_mask){
	switch(port_index){
	case PORTA:	{
				volatile unsigned long delay;
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay		
				GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;   	  //unlock port			  
				GPIO_PORTA_CR_R |= pins_mask;				  //enable changes to all pins of the portA
				GPIO_PORTA_AMSEL_R &= ~pins_mask;     		  // Disable analog function
				GPIO_PORTA_PCTL_R &= ~GPIO_PCTL_mask;         // GPIO clear bit PCTL  
				GPIO_PORTA_AFSEL_R &= ~pins_mask;      		  // No alternate function
				GPIO_PORTA_DEN_R |= pins_mask;				  		//i made all pins of the portA digital 
				break;}	
	
	case PORTB:	{
				volatile unsigned long delay;
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay	
				GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;   	  //unlock		  
				GPIO_PORTB_CR_R |= pins_mask;					         //enable changes to all pins of the portB	
				GPIO_PORTB_AMSEL_R &= ~pins_mask;              // Disable analog function
				GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_mask;         // GPIO clear bit PCTL  
				GPIO_PORTB_AFSEL_R &= ~pins_mask;              // No alternate function
				GPIO_PORTB_DEN_R |= pins_mask;			  					//i made all pins of the portB digital
				break;
				}	
	
	case PORTC:	{
				volatile unsigned long delay;
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay	
				GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;   	  //unlock	  
				GPIO_PORTC_CR_R |= pins_mask;					  //enable changes to all pins of the portC
				GPIO_PORTC_AMSEL_R &= ~pins_mask;      		  // Disable analog function
				GPIO_PORTC_PCTL_R &= ~GPIO_PCTL_mask;  		  // GPIO clear bit PCTL  
				GPIO_PORTC_AFSEL_R &= ~pins_mask;      		  // No alternate function
				GPIO_PORTC_DEN_R |= pins_mask;				  //i made all pins of the portC digital
				break;
				}	
	
	case PORTD:	{
				volatile unsigned long delay;
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay		
				GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;   	  //unlock	  
		    GPIO_PORTD_AMSEL_R &= ~pins_mask;              // Disable analog function
				GPIO_PORTD_PCTL_R &= ~GPIO_PCTL_mask;         // GPIO clear bit PCTL  
				GPIO_PORTD_AFSEL_R &= ~pins_mask;      		  // No alternate function
				GPIO_PORTD_CR_R |= pins_mask;					  //enable changes to all pins of the portD
				GPIO_PORTD_DEN_R |= pins_mask;				  //i made all pins of the portD digital
				break;
				}	
			
	case PORTE:	{
				volatile unsigned long delay;
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay	
				GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;   	  //unlock	  
				GPIO_PORTE_CR_R |= pins_mask;					  //enable changes to all pins of the portE
				GPIO_PORTE_AMSEL_R &= ~pins_mask;              // Disable analog function
				GPIO_PORTE_PCTL_R &= ~GPIO_PCTL_mask;           // GPIO clear bit PCTL  
				GPIO_PORTE_AFSEL_R &= ~pins_mask;              // No alternate function
				GPIO_PORTE_DEN_R |= pins_mask;				  //i made all pins of the portE digital
				break;
				}	

	case PORTF:	{
				volatile unsigned long delay;			
				SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;  //enable clock
				delay = SYSCTL_RCGCGPIO_R;        		  //delay	
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   	  //unlock	  
				GPIO_PORTF_CR_R |= pins_mask;					  //enable changes to all pins of the portF
				GPIO_PORTF_AMSEL_R &= ~pins_mask;              // Disable analog function
				GPIO_PORTF_PCTL_R &= ~GPIO_PCTL_mask;  		  // GPIO clear bit PCTL  
				GPIO_PORTF_AFSEL_R &= ~pins_mask;              // No alternate function
				GPIO_PORTF_DEN_R |= pins_mask;				  //i made all pins of the portF digital
				break;
				}	
			}
}
