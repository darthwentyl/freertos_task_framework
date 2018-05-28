// Kernel modules
#include <FreeRTOSConfig.h>
#include <FreeRTOS.h>

#include <task.h>
#include <queue.h>

#include <ActiveTask.h>
#include <MsgBase.h>
#include <Msg.h>
#include <ComponentManager.h>

#define mainQUEUE_LENGTH 				    (1)
#define	mainQUEUE_TOOGLE_TASK_PRIORITY		(tskIDLE_PRIORITY + 1)

void handle(void* pvParameters);

void runActiveTask(ActiveTask* activeTask, const char* taskName)
{
	unsigned payloadSize = 2*sizeof(Address) + sizeof(unsigned short) + 20;
	activeTask->xQueue = xQueueCreate(mainQUEUE_LENGTH, payloadSize);
	registerComponent(taskName, activeTask->xQueue);
	if(NULL != activeTask->xQueue)
	{
		xTaskCreate( handle
				   , taskName
				   , configMINIMAL_STACK_SIZE
				   , activeTask
				   , mainQUEUE_TOOGLE_TASK_PRIORITY
				   , NULL);
	}
}

void handle(void* pvParameters)
{
	MsgBase msg;
	ActiveTask* activeTask = (ActiveTask*)pvParameters;
	msg.receiverAddress = activeTask->xQueue;
	for(;;)
	{
		receive(&msg);
		activeTask->handleMsg(&msg, &(activeTask->item));
		vTaskDelay(500u/portTICK_PERIOD_MS);
	}
}
