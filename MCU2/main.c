#include "tm4c123gh6pm.h"
#include "lcd.h"
#include "delay.h"
#include "typedefs.h"
#include "MCAL.h"
#include "button.h"
#include "UART.h"
#include "Potentiometer.h"
#include "LED.h"
#include "temp_sensor.h"
#include "stepper.h"
#include <stdint.h>
	
int main(void){
	uint16_t pot_value = 0;
	UART_init();
	delayms(20);
	LED_init();
	delayms(20);
	timer_init();
	delayms(20);
	ADC0_init_temp();
	delayms(20);
	StepMotorInit();
	delayms(20);
	while(1){
		
		UART_Write(read_temp()); //Send temperature to other board.
		if(UART_Read() == 'A') //That means the next 2 bytes to be sent will construct the potentiometer value in the other board
		{
			pot_value = 0;
			pot_value = (uint16_t)UART_Read() & 0x00FF;
			pot_value = ((uint16_t)UART_Read() << 8) | pot_value;
			LED_SetDutyCycle(pot_value);   
		}
		
		
		if(UART_Read() == 'B') //Clockwise button pressed
		{
			turn30_CW();
		}
		delayms(60);
		if(UART_Read() == 'C') //Anti-clockwise button pressed
		{
			turn30_CCW();
		}
		
		LED_SetDutyCycle(pot_value);
		delayms(100);		
	} 
}
