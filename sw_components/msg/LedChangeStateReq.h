#ifndef __MSG_LED_CHANGE_STATE_REQ_H__
#define __MSG_LED_CHANGE_STATE_REQ_H__

#include <Led.h>
#include <MsgBase.h>

typedef struct
{
	unsigned short state;
}LedChangeStateReq;

typedef union
{
	LedChangeStateReq msg;
	char payload[sizeof(LedChangeStateReq)];
}LedChangeStateMsg;

#endif // __MSG_LED_CHANGE_STATE_REQ_H__
