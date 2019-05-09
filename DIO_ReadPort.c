#include "tm4c123gh6pm_custom.h"

#include "MCAL.h"

#include <stdint.h>



uint8_t DIO_ReadPort( uint8_t port_index , uint8_t pins_mask )

{

   uint8_t pins_level;

   switch(port_index)

   {



	case PORTA:

		   

                 pins_level=(GPIO_PORTA_DATA_R & pins_mask);

                 break;



	case PORTB:

		   

                 pins_level=(GPIO_PORTB_DATA_R & pins_mask);

                 break;

			

	case PORTC:



                 pins_level=(GPIO_PORTC_DATA_R & pins_mask);

                 break;



	case PORTD:

		   

                 pins_level=(GPIO_PORTD_DATA_R & pins_mask);

                 break;



	case PORTE: 

		   

                 pins_level=(GPIO_PORTE_DATA_R & pins_mask);

                 break;



	case PORTF:

		   

                 pins_level=(GPIO_PORTF_DATA_R & pins_mask);

                 break;



   }

  return pins_level;

}               
