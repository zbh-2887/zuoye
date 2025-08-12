#include "gpio.h"
#include "main.h"
#include "beep.h"

#define BEEP_PORT GPIOA
#define BEEP_PIN GPIO_PIN_8

void BEEP_ON(void)
{
	HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_SET);
}

void BEEP_OFF(void)
{
	HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_RESET);
}