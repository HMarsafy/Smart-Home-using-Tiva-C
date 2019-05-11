#include <stdint.h>
#include "app.h"
#include "MCAL.h"
#include "delay.h"


uint32_t APP_uart_decoder(uint8_t *type){
  uint32_t i;
  char* ptr;
  *type = 0;
  if(UART_Read() == "q") //That's sent before a temperature sensor reading is sent, so the next 4 bytes constructs the temp sensor reading
  {
    ptr = (char *)&i;
    for (x = 0; x < sizeof(i); x++)
      *ptr++ = UART_Read();
    *type = 1;
    return i;
  }
  else if(UART_Read() == "A") //That means the button which makes the stepper rotate 30 degs clockwise has been pressed
  {
    *type = 2;
    return (uint32_t)("A");
  }
  else if(UART_Read() == "B") //That means the button which makes the stepper rotate 30 degs anti-clockwise has been pressed
  {
    *type = 2; 
    return (uint32_t)("B");
  }
  return 0;
}
