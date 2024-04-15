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

void init_tim6()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->ARR = 8000 - 1;
	TIM6->PSC = 1000 - 1;

	TIM6->DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(TIM6_DAC_IRQn, 6);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void start_tim6()
{
	TIM6->CR1 |= TIM_CR1_CEN;
}
