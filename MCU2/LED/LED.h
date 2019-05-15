#ifndef __RGBLED_H__
#define __RGBLED_H__

#include <stdint.h>

#define GPIO_PF2_M	0x04

void LED_init(void);

void LED_SetDutyCycle(uint16_t duty_cycle);

#endif // __RGBLED_H__
