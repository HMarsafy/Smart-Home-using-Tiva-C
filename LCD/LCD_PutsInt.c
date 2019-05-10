#include <stdio.h>

#include <stdint.h>

#include "MCAL.h"

#include "LCD.h"





void LCD_PutsInt(int32_t num){

	char buffer[8];

	sprintf(buffer,"%d", num);

	LCD_Puts(buffer);

}
