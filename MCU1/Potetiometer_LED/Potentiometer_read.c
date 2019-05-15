#include "potentiometer.h"

uint16_t Potentiometer_read(void){
	
	 ADC0_PSSI_R = ADC0_PSSI_SS3;
	while((ADC0_RIS_R& ADC0_RIS_INR3)!=ADC0_RIS_INR3);	//polling on bit INR3 for sequencer 3 till be assigned to end conv
	ADC0_ISC_R = ADC0_RIS_INR3;                    //clear bit INR3 by assign 1 in bit 3 in isc
	return (ADC0_SSFIFO3_R&0xFFF);                  //return value on fifo
	
	
}
