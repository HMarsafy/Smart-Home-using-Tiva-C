#include "MCAL.h"
#include <stdint.h>

void DIO_WritePortWord(unsigned char word,uint32_t port, uint8_t mask) {
		word = word & (mask);
		HWREG(port+0x3FC) = (word);
}
