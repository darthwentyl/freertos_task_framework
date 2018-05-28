#ifndef __MSG_MSG_BASE_H__
#define __MSG_MSG_BASE_H__

#include <MsgId.h>
#include <queue.h>

typedef QueueHandle_t Address;

typedef struct
{
	Address senderAddress;
	Address receiverAddress;
	unsigned short msgId;
	char payload[20];
}MsgBase;

MsgBase createMsg(Address from, Address to, const MsgId id);

#endif // __MSG_MSG_BASE_H__
