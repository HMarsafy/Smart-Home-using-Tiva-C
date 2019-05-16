#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "temp_sensor.h"
#include <stdint.h>


#define ADC0_SS0_PRI 			0x3

#define ADC0_SS1_PRI 			(0x2 << 4)

#define ADC0_SS2_PRI 			(0x1 << 8)

#define ADC0_SS3_PRI 			(0x0 << 12)

#define ADC0_ACTSS_SS3     0x8

#define ADC0_EMUX_SS3			(0x0 << 12)                                              

#define ADC0_SSMUX3				 0x0	                                                  

#define ADC0_SSCTL3_IE0		(0x1 << 2)

#define ADC0_SSCTL3_END0	(0x1 << 1)

#define GPIO_PE3_M         (1  << 4)

#define ADC0_PSSI_SS3			(0x1 << 3)

#define ADC0_RIS_INR3			(0x1 << 3)

#define ADC0_SSCTL3_TS0    (1  << 3 )

void ADC0_init_temp(void)
{
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	delay = SYSCTL_RCGCGPIO_R;
	SYSCTL_RCGC0_R |= 0x00010000;
	delay = SYSCTL_RCGC0_R;
	ADC0_SSPRI_R = 0x0123;
	ADC0_ACTSS_R &= ~ADC0_ACTSS_SS3;
	ADC0_EMUX_R &= ~(0xF000) | 0x50;
	ADC0_SSMUX3_R = 0x0;
	ADC0_SSCTL3_R |= (ADC0_SSCTL3_IE0 | ADC0_SSCTL3_END0 | ADC0_SSCTL3_TS0);
	ADC0_ACTSS_R |= ADC0_ACTSS_SS3;
}
