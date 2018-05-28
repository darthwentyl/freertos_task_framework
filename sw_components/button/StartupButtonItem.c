#include <StartupButtonItem.h>
#include <stm32f0xx_gpio.h>
#include <memory.h>

#include <ComponentsName.h>
#include <Msg.h>
#include <string.h>

StartupState createButtonItem(StartupItem** self)
{
	StartupButtonItem* pSelf = (StartupButtonItem*)malloc(sizeof(StartupButtonItem));
	pSelf->startupItem.currentState = NO_INIT;
	return NO_INIT;
}

StartupState initButtonItem(StartupItem** self)
{
	StartupButtonItem* pSelf = (StartupButtonItem*)(*self);
	pSelf->startupItem.currentState = NO_RUN;
	return NO_RUN;
}

StartupState runButtonItem(StartupItem** self)
{
//	StartupButtonItem* pSelf = (StartupButtonItem*)(*self);
	return STARTUP_FINISH;
}

