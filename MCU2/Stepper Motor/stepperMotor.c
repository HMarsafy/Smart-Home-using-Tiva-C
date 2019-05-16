#include "tm4c123GH6pm.h"
#include "MCAL.h"
#include <stdint.h>


struct State{

  unsigned char out;     // PB7-4 to right motor, PB3-0 to left         

  unsigned short wait;   // in 10ms units      

  unsigned char next[4]; // input 0x00000 (0) means no buttom is pressed ,

                         // input 0x00001 (1), means buttom f0 is pressed (cw)
                         // input 0x10000 (16) means buttom f4 is pressed (CCW)
	
                       	//  input 0x10001 (17) means both bottom is pressed

};
typedef const struct State StateType;

StateType Fsm[4] = {

  {0x05, 2, {0, 1, 3, 0}}, // S0) initial state and state where bumpers are checked

  {0x06, 2, {1, 2, 0, 1} }, // S1) 

  {0x0A, 2, {2, 3, 1, 2} }, // S2) 

  {0x09, 2, {3, 0, 2, 3} } // S3)
};

unsigned char cState;      // current State (0 to 3) 


void stepperMotor(void){
  unsigned short numofstep = 0;
  cState = 0;     		// initial state = 0
	while(num ofstep < 5){
  //when numofstep = 5 this mean the stepper make 30 degree 
		unsigned long input
    // output based on current state

    GPIO_PORTB_DATA_R |= Fsm[cState].out; // step motor

    // wait for time according to state

    delayms(Fsm[cState].wait);

    // get input    

    input =(SW_F4_F0input())& 0x11; // Input 0,1,16,17
			
	  if(input == 16 )
			input = 2;
		if(input == 17 )
			input = 3;

    // change the state based on input and current state

    cState = Fsm[cState].next[input];
    numofstep ++;

 		
	} 
  }
