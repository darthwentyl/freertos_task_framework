// Kernel modules
#include <FreeRTOS.h>
#include <task.h>

#include <MsgBase.h>

MsgBase createMsg(Address from, Address to, const MsgId id)
{
	MsgBase msg;
	msg.senderAddress = from;
	msg.receiverAddress = to;
	msg.msgId = id;
	return msg;
}
