#ifndef LCD_HEADER
#define LCD_HEADER


#include <stdint.h>

#include "MCAL/tm4c123gh6pm.h"
#include "delay/delay.h"
#include "MCAL/MCAL.h"

//#define LCD_8BIT_MODE //To switch to 4-bit mode comment this define, to switch to 8-bit mode un-comment this define.

/*
 * Control lines will be connected to PORTB (RS, RW, E)
 * Data lines will be connected to PORTA (D0 --> D7 incase of 8-bit mode)
 * 										 (D4 --> D7 incase of 4-bit mode)
*/
#define LCD_CTRL_PORT GPIO_PORTB_DATA_R
#define LCD_DATA_PORT GPIO_PORTA_DATA_R

#define DATA_8BIT_MASK 0xFF //To select all data pins in 8-bit mode
#define DATA_4BIT_MASK 0xF0 //To select all data pins in 4-bit mode

/* Assuming the CTRL pins will be at pin0, pin1, pin2 */
#define CTRL_MASK 0x07 //Can be used to do actions on RS, RW, E at the same time
#define RS_MASK 0x01 //Pin0
#define RW_MASK 0x02 //Pin1
#define E_MASK  0x04 //Pin2

/* LCD Defined commands */

#define LCD_8bit_1line_Mode 0x30
#define LCD_8bit_2line_Mode 0x38
#define LCD_4bit_1line_Mode 0x20
#define LCD_4bit_2line_Mode 0x28
#define LCD_4bit_Data_Mode 0x02
#define LCD_Display_Off_Cursor_Off 0x08
#define LCD_Display_On_Cursor_Off 0x0C
#define LCD_Display_On_Cursor_On 0x0E
#define LCD_Display_On_Cursor_Blink 0x0F
#define LCD_Shift_Left 0x18
#define LCD_Shift_Right 0x1C
#define LCD_Cursor_Shift_Right_One 0x10
#define LCD_Cursor_Shift_Left_One 0x14
#define LCD_Clear_Display 0x01
#define LCD_Set_Cursor_Location 0x00 //Can be changed depending on the LCD Display DDRAM Addresses

/*initializes the LCD*/
void LCD_Init(void);

/*Take the commands as a hex number and executes it*/
void LCD_Command(uint8_t cmd);

/*Clear the LCD and returns the cursor to the start*/
void LCD_Clear(void);

/*Prints a single character on the current cursor location*/
void LCD_PrintChar(char ch);

/*Prints a whole string on the LCD*/
void LCD_Puts(const char* str);

/*Moves the cursor to the specified (row,col)*/
void LCD_GoToRowCol(uint8_t row, uint8_t col);


void LCD_PutsInt(int32_t data);

#endif //LCD_HEADER
