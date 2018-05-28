#include <stdint.h>
#include <system_stm32f0xx.h>
#include <stm32f0xx_exti.h>
#include <stm32f0xx_gpio.h>
#include <stm32f0xx_rcc.h>
#include <stm32f0xx_misc.h>
#include <stm32f0xx_syscfg.h>

void init_leds();
void init_button();

void init_gpio()
{
	init_leds();
	init_button();
}

void init_leds()
{
	GPIO_InitTypeDef InitGpio;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

	InitGpio.GPIO_Pin = (GPIO_Pin_8 | GPIO_Pin_9);
	InitGpio.GPIO_Mode = GPIO_Mode_OUT;
	InitGpio.GPIO_Speed = GPIO_Speed_Level_1;
	InitGpio.GPIO_OType = GPIO_OType_PP;
	InitGpio.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOC, &InitGpio);
}

void init_button()
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

//	EXTI_GenerateSWInterrupt(EXTI_Line0);
}

//void EXTI0_1_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
//	{
//		/* Clear the EXTI line 0 pending bit */
//		EXTI_ClearITPendingBit(EXTI_Line0);
//	}
//}
