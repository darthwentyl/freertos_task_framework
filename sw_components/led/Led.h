#ifndef __LED_LED_H__
#define __LED_LED_H__

#include <stm32f0xx.h>
#include <stdint.h>
#include <ActiveTask.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#define GPIO uint16_t

typedef enum
{
	OFF = 1,
	ON  = 2
}LedState;

typedef struct
{
	GPIO ledPin;
	GPIO_TypeDef* port;
	LedState state;
}Led;

void ledOn(Led** led);
void ledOff(Led** led);

#endif // __LED_LED_H__
