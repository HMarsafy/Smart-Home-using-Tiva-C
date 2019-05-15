#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "potentiometer.h"

void Potentiometer_init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;  //enable clock
	delay = SYSCTL_RCGCGPIO_R;        		  //delay		
	GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;   	  //unlock
	GPIO_PORTE_CR_R |= 0x04;	
	GPIO_PORTE_DIR_R &= ~0x04;      // 2) make PE2 input
  GPIO_PORTE_AFSEL_R |= 0x04;     // 3) enable alternate function on PE2
  GPIO_PORTE_DEN_R &= ~0x04;      // 4) disable digital I/O on PE2
  GPIO_PORTE_AMSEL_R |= 0x04;     // 5) enable analog function on PE2
	SYSCTL_RCGC0_R |= 0x00010000;   // 6) activate ADC0 
	delay = SYSCTL_RCGC2_R;         

  SYSCTL_RCGC0_R &= ~0x00000800;  // 7) configure for 500K 
  ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger
  ADC0_SSMUX3_R &= ~0x000F;       // 11) clear SS3 field
	ADC0_PSSI_R |= 0x00000008;
  ADC0_SSMUX3_R = 0x1;             //    set channel Ain9 (PE4)
  ADC0_SSCTL3_R = 0x0004;         // 12) no TS0 D0, yes IE0 END0
  ADC0_ACTSS_R |= 0x0008;         // 13) enable sample sequencer 3
}
