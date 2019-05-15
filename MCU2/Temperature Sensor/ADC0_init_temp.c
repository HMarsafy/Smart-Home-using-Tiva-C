void ADC0_init_temp(void)
{
	volatile int delay;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	delay = SYSCTL_RCGCGPIO_R;
	SYSCTL_RCGC0_R |= 0x00010000;
	delay = SYSCTL_RCGC0_R;
	ADC0_SSPRI_R = 0x0123;
	ADC0_ACTSS_R &= ~ADC0_ACTSS_SS3;
	ADC0_EMUX_R &= ~(0xF000) | 0x50;
	ADC0_SSMUX3_R = 0x0;
	ADC0_SSCTL3_R |= (ADC0_SSCTL3_IE0 | ADC0_SSCTL3_END0 | ADC0_SSCTL3_TS0);
	ADC0_ACTSS_R |= ADC0_ACTSS_SS3;
}