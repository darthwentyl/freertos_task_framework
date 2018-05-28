#ifndef __MSG_MSG_H__
#define __MSG_MSG_H__

#include <MsgBase.h>

void send(MsgBase* msg);
void receive(MsgBase* msg);

Address getReceiverAddress(const char* name);

#endif // __MSG_MSG_H__
