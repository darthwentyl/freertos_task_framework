#include <StartupLedItem.h>
#include <stm32f0xx_gpio.h>
#include <memory.h>

#include <ComponentsName.h>
#include <LedChangeStateReq.h>
#include <Msg.h>
#include <string.h>
void setInitValue(LedActiveTask* item, GPIO pin, const char* taskName);

StartupState createLedItem(StartupItem** self)
{
	StartupLedItem* pSelf = (StartupLedItem*)malloc(sizeof(StartupLedItem));
	pSelf->startupItem.currentState = NO_INIT;
	*self = (StartupItem*)pSelf;
	return NO_INIT;
}

StartupState initLedItem(StartupItem** self)
{
	StartupLedItem* pSelf = (StartupLedItem*)(*self);
	setInitValue(&pSelf->ledPC8, GPIO_Pin_8, LED_PC8);
	setInitValue(&pSelf->ledPC9, GPIO_Pin_9, LED_PC9);
	pSelf->startupItem.currentState = NO_RUN;
	return NO_RUN;
}

StartupState runLedItem(StartupItem** self)
{
	MsgBase req;
	StartupLedItem* pSelf = (StartupLedItem*)(*self);
	runActiveTask((ActiveTask*)(&pSelf->ledPC8), LED_PC8);
	runActiveTask((ActiveTask*)(&pSelf->ledPC9), LED_PC9);
	req.msgId = LED_CHANGE_STATE_REQ;
	req.receiverAddress = getReceiverAddress(LED_PC8);
	req.senderAddress = getReceiverAddress(LED_PC9);
	LedChangeStateMsg state;
	state.msg.state = 0;
	state.msg.state = ON;
	strcpy(req.payload, state.payload);
	send(&req);
	return STARTUP_FINISH;
}

void setInitValue(LedActiveTask* item, GPIO pin, const char* taskName)
{
	item->ledItem.led.ledPin = pin;
	item->ledItem.led.port = GPIOC;
	item->ledItem.led.state = 0;
	item->ledItem.led.state = OFF;
	item->activeTask.item = (ActiveTaskItem*)(&item->ledItem);
	item->activeTask.handleMsg = handleLedMsg;
}
