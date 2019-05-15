#include "MCAL.h"
#include <stdint.h>
#include "LCD.h"
/* this function print Given string on the LCD */
void LCD_Puts(const char* str)
{
	while(*str != '\0')
	{
		LCD_PrintChar(*str);
		str++;
	}
}
