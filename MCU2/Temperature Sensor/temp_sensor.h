#ifndef TEMP_SENSOR_HEADER
#define TEMP_SENSOR_HEADER

#include "tm4c123gh6pm.h"
#include <stdint.h>

void itoa (int data,char buffer[] , int base);


void timer_init(void);

void ADC0_init_temp(void);

uint16_t read_temp(void);

#endif
