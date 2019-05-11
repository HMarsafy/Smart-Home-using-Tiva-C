#include "tm4c123gh6pm_custom.h"
#include "MCAL.h"
#include <stdint.h>



uint32 MCAL_Temp_Read(void)
{
	volatile uint32 temperature;
	uint32 ADC_Value = ADC_Read();
	temperature = 147 - (247 * ADC_Value) / 4096;
	return temperature;
}
