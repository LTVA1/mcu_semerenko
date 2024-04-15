#include "main.h"
#include "gpio.h"

void TIM6_DAC_IRQHandler()
{
	TIM6->SR &= ~TIM_SR_UIF;
	blinkled();
}

void Set48MHz()
{
	RCC->CR &= ~RCC_CR_PLLON;
	while(RCC->CR & RCC_CR_PLLRDY) {} //until PLL unlocked

	RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_DIV2; //unndeeded?
	RCC->CFGR |= RCC_CFGR_PLLMUL12; //8 / 2 * 12 = 48 MHz
	RCC->CR |= RCC_CR_PLLON; //turn on

	while(!(RCC->CR & RCC_CR_PLLRDY)) {} //until PLL locked

	RCC->CFGR |= RCC_CFGR_SW_1;

	while(!(RCC->CFGR & RCC_CFGR_SWS_1)) {}

	//SystemCoreClockUpdate();
}

int main(void)
{
	Set48MHz();
	init_portc();
	init_tim6();
	start_tim6();

	while (1)
	{
		for(int i = 0; i < 600000; i++) {}
		//blinkled();
	}
}
