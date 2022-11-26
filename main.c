/**
  ******************************************************************************
  * @file    main.c
  * @author  jarray fakhreddine
  * @brief   LED Blinking with a Push Button  
  * @version V1.0.0
  * @date    26-11-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/


#include "GPIO.h"  
#include "LED.h"
/* Private define ------------------------------------------------------------*/
   
int main()
{
 // GPIO_Clock_Enable( (uint32_t*) 0x40020401);
  GPIO_Clock_Enable(GPIOD);
  GPIO_Config (GPIOD, PIN12, OUTPUT, OUTPUT_OPEN_DRAIN , LOW_SPEED);
  GPIO_Config (GPIOD, PIN9, INPUT, OUTPUT_OPEN_DRAIN , LOW_SPEED);

  GPIO_Write_Pin(GPIOD, PIN12, SET);
  GPIO_Write_Pin(GPIOD, PIN0, RESET); 
  
  uint8_t ReadPinTest = (GPIO__Read_Pin(GPIOD, PIN10));
  uint8_t ReadPinTest1 = (GPIO__Read_Pin(GPIOD, PIN9));
  while(1)
  {
  }
}

/**************************************END OF FILE**************************************/