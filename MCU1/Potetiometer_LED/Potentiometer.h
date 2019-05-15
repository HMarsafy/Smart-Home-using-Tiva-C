#ifndef __POTENTIOMETER_H__
#define __POTENTIOMETER_H__

#include <stdint.h>
#define ADC_RESOLUTION	(3.3 / 4096)

void Potentiometer_init(void);

uint16_t Potentiometer_read(void);

#endif // _
