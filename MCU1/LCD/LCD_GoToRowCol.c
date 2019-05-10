#include <stdint.h>
#include "LCD.h"


void LCD_GoToRowCol(uint8_t row, uint8_t col)
{
	uint8_t address;
	/*Calculate the address location*/
	switch(row)
	{
	case 0:
		address = col;
		break;
	case 1:
		address = col + 0x40;
		break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_Command(address | LCD_Set_Cursor_Location);
}
