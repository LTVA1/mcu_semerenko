#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f0xx.h"

void init_portc();
void blinkled();

void init_tim6();
void start_tim6();

#endif /* GPIO_H_ */
