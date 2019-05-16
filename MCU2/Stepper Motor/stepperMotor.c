#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "MCAL.h"
#include "stepper.h"
#include "delay.h"

void StepMotorInit(void){
	
	 volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTLB_MASK ;          // 1) activate Port B

  delay = SYSCTL_RCGC2_R;          // allow time for clock to stabilize

   GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY ;           // 2) no need to unlock PB3-0

  GPIO_PORTB_AMSEL_R &=~GPIOB3TO0_MASK;       // 3) disable analog functionality on P3-0

  GPIO_PORTB_PCTL_R &=~ GPIOB3TO0_PCTL_MASK ;  // 4) configure PB3-0 as GPIO
	

  GPIO_PORTB_DIR_R |= GPIOB3TO0_MASK ;  // 5) make PB3-0 out

  GPIO_PORTB_AFSEL_R &=~ GPIOB3TO0_MASK;       // 6) disable alt funct on PB3-0

  GPIO_PORTB_DR8R_R |= GPIOB3TO0_MASK;        // enable 8 mA drive on PB3-0

  GPIO_PORTB_DEN_R |= GPIOB3TO0_MASK;         // 7) enable digital I/O on PB3-0
	
}


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
