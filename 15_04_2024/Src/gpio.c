#include "gpio.h"

void init_portc()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_0;
	GPIOC->ODR |= GPIO_ODR_8;
}

void blinkled()
{
	GPIOC->ODR ^= GPIO_ODR_8;
}
