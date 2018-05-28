#ifndef __ACTIVE_TASK_ACTIVE_TASK_H__
#define __ACTIVE_TASK_ACTIVE_TASK_H__

#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <MsgBase.h>

typedef struct
{

}ActiveTaskItem;

typedef struct
{
	ActiveTaskItem* item;
	QueueHandle_t xQueue;
	void (*handleMsg)(MsgBase*, ActiveTaskItem**);
}ActiveTask;

void runActiveTask(ActiveTask* activeTask, const char* taskName);

#endif //  __ACTIVE_TASK_ACTIVE_TASK_H__
