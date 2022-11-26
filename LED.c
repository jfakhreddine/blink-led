#include "LED.h"

#define  GPIO_NOPULL        0u /*!< No Pull-up or Pull-down activation */  
#define  GPIO_PULLUP        1u  /*!< Pull-up activation                */
#define  GPIO_PULLDOWN      2u/*!< Pull-down activation        */
#define __HAL_RCC_GPIOA_CLK_ENABLE
void AssertValid(void)
{
  __asm("NOP");
}

void AssertFailed(void)
{
  while(1){}
}

#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())


void Init_OnBoard_LEDs_PIN(void)
{
  Init_OnBoard_LEDs(); 
  configure_Button(); 
  GPIO_PinState state; 
  state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); 
  if(state)
  {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
  }
  else
  {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
  }
}

void Init_OnBoard_LEDs(void)
{
  __HAL_RCC_GPIOD_CLK_ENABLE(); //Enable clock to GPIOD
  GPIO_InitTypeDef BoardLEDs; // declare a variable of type struct GPIO_InitTypeDef
  BoardLEDs.Mode = GPIO_MODE_OUTPUT_PP; // set pin mode to output 
  BoardLEDs.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15; // select pins PD12-PD15 
  HAL_GPIO_Init(GPIOD, &BoardLEDs); // initialize PD12-PD15 pins by passing port name and address of BoardLEDs struct
}

void configure_Button(void)
{
  __HAL_RCC_GPIOD_CLK_ENABLE(); //Enable clock to GPIOD
  GPIO_InitTypeDef BoardLEDs; // declare a variable of type struct GPIO_InitTypeDef
  BoardLEDs.Mode = GPIO_MODE_OUTPUT_PP; // set pin mode to output 
  BoardLEDs.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15; // select pins PD12-PD15 
  HAL_GPIO_Init(GPIOD, &BoardLEDs); // initialize PD12-PD15 pins by passing port name and address of BoardLEDs struct
}

