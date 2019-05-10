#ifndef MCAL_HEADER
#define MCAL_HEADER

#include <stdint.h>



/* PORT INDEXES */
#define PORTA (0u)
#define PORTB (1u)
#define PORTC (2u)
#define PORTD (3u)
#define PORTE (4u)
#define PORTF (5u)

/* PULL-UP PULL-DOWN */
#define DISABLE (0u)
#define ENABLE (1u)

/* ENUMBERATIONS */
enum Port_PinDirectionType{PORT_PIN_IN, PORT_PIN_OUT};

enum Dio_LevelType{STD_LOW, STD_HIGH};


/* PORT DRIVER */

/*
 * Initialize port based on the port_index
 * instead of using numbers, PORTA, PORTB,
 * PORTC, PORTD, PORTE & PORTF can be used
 * 1. Enable the clock for the port
 * 2. Unlock the port
 * 3. Set mode to digital
 * Example: Port_Init(PORTA)
 */
void Port_Init(uint8_t port_index);


/*
 * Change the direction of the SELECTED PINS by pins_mask
 * in the port selected by port_index
 * Example: Port_SetPinDirection(PORTA, 0x000000AC, PORT_PIN_OUT);
 * Note that 0xA is equivalent to 0b1010 & 0xC to 0b1100
 * this example would set pin number 2, 3, 5, 7 to output pins
 */
void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, enum Port_PinDirectionType pins_direction);


/*
 * If enable is 1 (ENABLE), the selected pins by pins_mask in the
 * port selected by port_index will be connected to internal pull-up resistor
 * if enable is 0 (DISABLE, the selected pins will not be connected to the internal
 * pull-up resistor.
 * Example: Port_SetPinPullUp(PORTB, 0x00000003, ENABLE);
 * this example would make pin number 0, 1 connected to the internal pull-up resistor
 */
void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable);


/*
 * If enable is 1 (ENABLE), the selected pins by pins_mask in the
 * port selected by port_index will be connected to internal pull-down resistor
 * if enable is 0 (DISABLE), the selected pins will not be connected to the internal
 * pull-down resistor.
 * Example: Port_SetPinPullDown(PORTB, 0x00000003, ENABLE);
 * this example would make pin number 0, 1 connected to the internal pull-down resistor
 */
void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable);


/* DIO DRIVER */

/*
 * Return the value of the PINS selected by pins_mask in the
 * port selected by port_index
 * Example: DIO_ReadPort(PORTC, 0x00000003);
 * this example would read pins 0 & 1 in portc
 * if the value returned is:
 * 0 --> both pins are 0
 * 1 --> PIN0 is 1, PIN1 is 0
 * 3 --> PIN0 & PIN1 are 1
 */
uint8_t DIO_ReadPort(uint8_t port_index, uint8_t pins_mask);


/*
 * Change the value of the pins selected by pins_masks in the
 * port selected by port_index to pins_level
 * Example: DIO_WritePort(PORTE, 0x00000005, STD_HIGH);
 * this example would set pin0 & pin2 to HIGH
 */
void DIO_WritePort(uint8_t port_index, uint8_t pins_mask, enum Dio_LevelType pins_level);

/*
 * Toggle the values of the pins selected by pins_masks in the
 * port selected by port_index
 */
void DIO_FlipPort(uint8_t port_index, uint8_t pins_mask);

#endif
