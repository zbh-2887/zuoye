#include "LED.h"
#include "gpio.h"

void LED_ON(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(50);
}