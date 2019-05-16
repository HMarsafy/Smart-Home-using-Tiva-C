void StepMotorInit(void){
	
	 volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTLB_MASK ;          // 1) activate Port B

  delay = SYSCTL_RCGC2_R;          // allow time for clock to stabilize

   GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY ;           // 2) no need to unlock PB3-0

  GPIO_PORTB_AMSEL_R &=~GPIOB3TO0_MASK;       // 3) disable analog functionality on P3-0

  GPIO_PORTB_PCTL_R &=~ GPIOB3TO0_PCTL_MASK ;  // 4) configure PB3-0 as GPIO
	

  GPIO_PORTB_DIR_R |= GPIOB3TO0_MASK ;  // 5) make PB3-0 out

  GPIO_PORTB_AFSEL_R &=~ GPIOB3TO0_MASK;       // 6) disable alt funct on PB3-0

  GPIO_PORTB_DR8R_R |= GPIOB3TO0_MASK;        // enable 8 mA drive on PB3-0

  GPIO_PORTB_DEN_R |= GPIOB3TO0_MASK;         // 7) enable digital I/O on PB3-0
	
}
