#include "main.h"
#include "gpio.h"

int main(void)
{
	init_portc();

	while (1)
	{
		for(int i = 0; i < 500000; i++) {}
		blinkled();
	}
}
