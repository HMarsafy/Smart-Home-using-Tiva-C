#include <stdint.h>


#define SYSCTLB_MASK  0x02
#define GPIOB3TO0_MASK 0x0F
#define GPIOB3TO0_PCTL_MASK 0x0000FFFF
#define SYSCTLF_MASK 0x20
#define PF0_MASK 0x01
#define PF0_PCTL_MASK 0x0F
#define PF4_MASK 0x10
#define PF4_PCTL_MASK 0xF0000


void turn30_CW(void);
void turn30_CCW(void);
void StepMotorInit(void);
uint8_t Is_Pressed(uint8_t port_index, uint8_t mask);
