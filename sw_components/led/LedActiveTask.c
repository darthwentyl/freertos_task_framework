#include <LedActiveTask.h>
#include <Led.h>
#include <LedChangeStateReq.h>
#include <Msg.h>
#include <ComponentsName.h>
#include <MsgId.h>
#include <string.h>

void handleLedMsg(MsgBase* msg, ActiveTaskItem** item)
{
	MsgBase req;
	LedChangeStateMsg state;
	state.msg.state = 0;
	strcpy(state.payload, msg->payload);
	LedActiveTaskItem* ledItem = (LedActiveTaskItem*)(*item);
	Led* led = &(ledItem->led);
	if(state.msg.state == ON)
	{
		ledOn(&led);
		state.msg.state = 0;
		state.msg.state = OFF;
	}
	else
	{
		ledOff(&led);
		state.msg.state = 0;
		state.msg.state = ON;
	}
	req.msgId = LED_CHANGE_STATE_REQ;
	req.receiverAddress = msg->senderAddress;
	req.senderAddress = msg->receiverAddress;
	strcpy(req.payload, state.payload);
	send(&req);
}
