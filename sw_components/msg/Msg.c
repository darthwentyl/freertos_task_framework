#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <string.h>
#include <memory.h>

#include <Msg.h>
#include <ComponentManager.h>

void send(MsgBase* msg)
{
	xQueueSend( msg->senderAddress, (void*)msg, ( TickType_t ) 0);
}

void receive(MsgBase* msg)
{
	xQueueReceive(msg->receiverAddress, (void*)msg, portMAX_DELAY);
}

Address getReceiverAddress(const char* name)
{
	return getHandlerPtr(name);
}
