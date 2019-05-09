#include "MCAL.h"

#include <stdint.h>

#include "LCD.h"

#include "tm4c123gh6pm.h"



void LCD_Init()

{

    Port_Init(LCD_CTRL_PORT); //initialize PORTB itself in order to assign the AFSEL and Clock and other relative registers

    Port_Init(LCD_DATA_PORT); //initialize PORTA

    

    Port_SetPinDirection(LCD_CTRL_PORT , CTRL_MASK , PORT_PIN_OUT); //set the first 3 pins of PORTB to OUTPUT

    

    #ifdef LCD_8BIT_MODE //use 8 bit mode and 2 lines

          Port_SetPinDirection(LCD_DATA_PORT , DATA_8BIT_MASK , PORT_PIN_OUT);

          LCD_Command(LCD_8bit_2line_Mode);

    #else //use 4 bit mode and 2 lines

          Port_SetPinDirection(LCD_DATA_PORT , DATA_4BIT_MASK , PORT_PIN_OUT); //let 4 bits only output

          LCD_Command(LCD_4bit_2line_Mode);

    #endif

          LCD_Command(LCD_Clear_Display); //give 1 to command to give clear command

          LCD_Command(LCD_Display_On_Cursor_Blink);//let cursor blink 

 }
