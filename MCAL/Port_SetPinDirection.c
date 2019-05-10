#include "MCAL.h"
#include <stdint.h>

void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, enum Port_PinDirectionType pins_direction)
{
	switch(port_index){
	case PORTA:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTA_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTA_DIR_R |= pins_mask;
				break;
				}
	case PORTB:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTB_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTB_DIR_R |= pins_mask;
				break;
				}
	case PORTC:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTC_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTC_DIR_R |= pins_mask;
				break;
				}
	case PORTD:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTD_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTD_DIR_R |= pins_mask;
				break;
				}
	case PORTE:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTE_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTE_DIR_R |= pins_mask;
				break;
				}
	case PORTF:{
				if(pins_direction == PORT_PIN_IN)
					GPIO_PORTF_DIR_R &= ~pins_mask;
				else if(pins_direction == PORT_PIN_OUT)
					GPIO_PORTF_DIR_R |= pins_mask;
				break;
				}
	}
}
