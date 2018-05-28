// Kernel modules
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <Led.h>
#include <stm32f0xx_gpio.h>

void ledOn(Led** led)
{
	if(OFF == (*led)->state)
	{
		(*led)->state = ON;
		GPIO_SetBits((*led)->port, ((*led)->ledPin));
	}
}

void ledOff(Led** led)
{
	if(ON == (*led)->state)
	{
		(*led)->state = OFF;
		GPIO_ResetBits((*led)->port, ((*led)->ledPin));
	}
}
