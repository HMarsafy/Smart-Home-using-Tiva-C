#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "MCAL.h"
#include "stepper.h"
#include "delay.h"

void turn30_CW(void)
{
	for(int i = 0; i < 38; i++)
	{
		GPIO_PORTB_DATA_R = 0x08;
		delayms(10);
		GPIO_PORTB_DATA_R = 0x01;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x02;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x04;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x08;
	}
}

void turn30_CCW(void)
{
		for(int i = 0; i < 38; i++)
	{
		GPIO_PORTB_DATA_R = 0x08;
		delayms(10);
		GPIO_PORTB_DATA_R = 0x04;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x02;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x01;
	  delayms(10);
	  GPIO_PORTB_DATA_R = 0x08;
	}
}
