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
	uint8_t temperature = 0;
	LCD_init();
	delayms(10);
	LCD_clearScreen();
	delayms(10);
	Potentiometer_init();
	LCD_displayStringRowColumn(0,0, "ADC0 initialized..");
	delayms(300); 
	UART_init();
	LCD_displayStringRowColumn(0,0, "UART initiazlied..");
	delayms(300);
	LED_init();
	LCD_displayStringRowColumn(0,0, "LEDs initialized..");
	delayms(300);
	LCD_clearScreen();
	
	Port_Init(PORTF, 0x11, 0x000F000F);
	Port_SetPinDirection(PORTF, 0x11, (enum Port_PinDirectionType) PORT_PIN_IN);
	Port_SetPinPullUp(PORTF, 0x11, 1);
	LCD_displayStringRowColumn(0,0, "Temperature = ");
	while(1){

		temperature = UART_Read();
		LCD_intgerToString(temperature + 5);	
		pot_value = Potentiometer_read() / 150; //150 is to make the potentiometer reading suitable for the LED duty cylce range (0 - 100) range
		UART_Write('A');
		UART_Write(pot_value & 0x00FF);
		UART_Write(pot_value & 0xFF00);
		delayms(20);

		
		if(Is_Pressed(PORTF, 0x01))
		{		
			UART_Write('B');
		}		
		else if(Is_Pressed(PORTF, 0x10))
		{
			UART_Write('C');
		}
	
		delayms(50);		
	} 
}
