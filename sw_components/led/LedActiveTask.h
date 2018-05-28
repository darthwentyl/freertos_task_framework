#ifndef __LED_LED_ACTIVE_TASK_H__
#define __LED_LED_ACTIVE_TASK_H__

#include <ActiveTask.h>
#include <Led.h>

typedef struct
{
	ActiveTaskItem activeTaskItem;
	Led led;
}LedActiveTaskItem;

typedef struct
{
	ActiveTask activeTask;
	LedActiveTaskItem ledItem;
}LedActiveTask;


void handleLedMsg(MsgBase* msg, ActiveTaskItem** item);

#endif // __LED_LED_ACTIVE_TAST_H__
