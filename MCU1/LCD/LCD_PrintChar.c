
void LCD_PrintChar(const char c){


	//select the data register 
	DIO_WritePort(PORTD, RS_MASK, (enum Dio_LevelType)STD_LOW);

	/*write operation */
	DIO_WritePort(PORTD, RW_MASK, (enum Dio_LevelType)STD_LOW);

     
	_delay_ms(2); 

	//Send the enable pulse
	DIO_WritePort(PORTD, E_MASK, (enum Dio_LevelType)STD_HIGH);
    
    
	_delay_ms(2); 

#ifdef LCD_8BIT_MODE

	LCD_DATA_PORT = c;
	
	_delay_ms(2);

	DIO_WritePort(PORTD,E_MASK,(enum Dio_LevelType)STD_LOW);

    _delay_ms(2);
    
#else
    //4bit mode  
    //first send the Most Sig 4 bit 
    LCD_DATA_PORT =( (c & 0xF0) | (LCD_DATA_PORT & 0x0F) );
    _delay_ms(1);

    DIO_WritePort(PORTD, E_MASK, (enum Dio_LevelType)STD_LOW);

    _delay_ms(1);

    //second send the Least sig 4 bit 
    DIO_WritePort(PORTD, E_MASK, (enum Dio_LevelType)STD_HIGH);

    _delay_ms(1);
    
    LCD_DATA_PORT = (((c & 0x0F) << 4) | (LCD_DATA_PORT & 0x0F));

    _delay_ms(1);

    DIO_WritePort(PORTD, E_MASK, (enum Dio_LevelType)STD_LOW);

    _delay_ms(1);

#endif 
}
