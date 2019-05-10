#include <stdint.h>

#include "tm4c123gh6pm_custom.h"

#include "MCAL.h"



void DIO_WritePort(uint8_t port_index , uint8_t pins_mask , enum Dio_LevelType pins_level)

{

   switch(port_index){

	               case PORTA:

		    {

                             switch(pins_level)

			    {

                                               case STD_LOW:

				               

                                                        GPIO_PORTA_DATA_R=(GPIO_PORTA_DATA_R &~ pins_mask);

		                                        break;

					       

                                               case STD_HIGH:

				               

                                                        GPIO_PORTA_DATA_R=(GPIO_PORTA_DATA_R | pins_mask);

                                                        break;

					       

			     }

		             break;

		      }

	               case PORTB:

		   {

                             switch(pins_level)

			   {

                                               case STD_LOW:

				              

                                                        GPIO_PORTB_DATA_R=(GPIO_PORTB_DATA_R &~ pins_mask);

		                                        break;

				              

                                               case STD_HIGH:

				              

                                                        GPIO_PORTB_DATA_R=(GPIO_PORTB_DATA_R | pins_mask);

					                break;

				              

				   

			   }

			   break;

		   }     

	               case PORTC:

		   {

                             switch(pins_level)

			   {

                                               case STD_LOW:

				              

                                                        GPIO_PORTC_DATA_R=(GPIO_PORTC_DATA_R &~ pins_mask);

		                                        break;

				              

                                               case STD_HIGH:

				              

                                                        GPIO_PORTC_DATA_R=(GPIO_PORTC_DATA_R | pins_mask);

					                break;

				              

			   }

			   break;

		   }

	               case PORTD:

		   {

                             switch(pins_level)

			   {

                                               case STD_LOW:

				               

                                                        GPIO_PORTD_DATA_R=(GPIO_PORTD_DATA_R &~ pins_mask);

						        break;

					       

                                               case STD_HIGH:

				               

                                                        GPIO_PORTD_DATA_R=(GPIO_PORTD_DATA_R | pins_mask);

						        break;

					       

			   }

			   break;

		   }

                                 

	               case PORTE:

		   {

                             switch(pins_level)

			   {

                                               case STD_LOW:

				     

                                                        GPIO_PORTE_DATA_R=(GPIO_PORTE_DATA_R &~ pins_mask);

						        break;

					     

                                               case STD_HIGH:

				              

                                                        GPIO_PORTE_DATA_R=(GPIO_PORTE_DATA_R | pins_mask);

						        break;

					      

			   }

			   break;

		   }

                                   

	

	               case PORTF:

		   {

                             switch(pins_level)

			   {

                                               case STD_LOW:

		   

                                                        GPIO_PORTF_DATA_R=(GPIO_PORTF_DATA_R &~ pins_mask);

		                                        break;

		   

                                               case STD_HIGH:

		   

                                                        GPIO_PORTF_DATA_R=(GPIO_PORTF_DATA_R | pins_mask);

		                                        break;

			   }

			   break;

		   }



}                 

}
