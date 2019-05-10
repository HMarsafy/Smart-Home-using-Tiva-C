void LCD_Command(uint8_t cmd)
{
	/*Select the command register*/
	DIO_WritePort(LCD_CTRL_PORT, RS_MASK, (enum Dio_LevelType) STD_LOW);
	/*Write operation*/
	DIO_WritePort(LCD_CTRL_PORT, RW_MASK, (enum Dio_LevelType) STD_LOW);
	_delay_us(1); /* delay for processing Tas = 50ns */
	/*Send the enable pulse*/
	DIO_WritePort(LCD_CTRL_PORT, E_MASK, (enum Dio_LevelType) STD_HIGH);
	_delay_us(1);	/* delay for processing Tpw - Tdws = 190ns */
#ifdef LCD_8BIT_MODE
	LCD_DATA_PORT = cmd;
	_delay_us(1); /* delay for processing Tdsw = 100ns */
	/* Clear the enable signal */
	DIO_WritePort(LCD_CTRL_PORT, E_MASK, (enum Dio_LevelType) STD_LOW);
	_delay_us(1); /* delay for processing Th = 13ns */
#else /*4 bits mode */
	/*Send the MS 4 bits first*/
	LCD_DATA_PORT = (cmd & 0xF0) | (LCD_DATA_PORT & 0x0F);
	_delay_us(1); /* delay for processing Tdsw = 100ns */
		/* Clear the enable signal */
	DIO_WritePort(LCD_CTRL_PORT, E_MASK, (enum Dio_LevelType) STD_LOW);
	_delay_us(1); /* delay for processing Th = 13ns */

	/*Then send the LS 4 bits*/
		/*Send the enable pulse*/
	DIO_WritePort(LCD_CTRL_PORT, E_MASK, (enum Dio_LevelType) STD_HIGH);
	_delay_us(1); /* delay for processing Tpw - Tdws = 190ns */
	LCD_DATA_PORT = ((cmd & 0x0F) << 4) | (LCD_DATA_PORT & 0x0F);
	_delay_us(1); /* delay for processing Tdsw = 100ns */
		/* Clear the enable signal */
	DIO_WritePort(LCD_CTRL_PORT, E_MASK, (enum Dio_LevelType) STD_LOW);
	_delay_us(1); /* delay for processing Th = 13ns */
#endif
}
