uint16_t read_temp(void)
{
	uint16_t temp;
	ADC0_PSSI_R = ADC0_PSSI_SS3;
	while((ADC0_RIS_R  &   8 == 0);
	temp = 147 - (247 * ADC0_SSFIFO3_R) / 4096;
	ADC0_ISC_R = 0;
	return temp;
}
