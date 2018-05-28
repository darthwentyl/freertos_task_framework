#include <ComponentManager.h>
#include <string.h>

typedef struct
{
	QueueHandle_t handler;
	char name[configMAX_TASK_NAME_LEN];
}QueueList;

static QueueList queueList[configQUEUE_REGISTRY_SIZE] = {{0 ,{0}}};

void initComponentList()
{
	unsigned i = 0;
	for(; i < configQUEUE_REGISTRY_SIZE; ++i)
	{
		memset((void*)queueList[i].name, 0, strlen(queueList[i].name));
		queueList[i].handler = NULL;
	}
}

void registerComponent(const char* name, QueueHandle_t handlerPtr)
{
	unsigned i = 0;
	for(; i < configQUEUE_REGISTRY_SIZE; ++i)
	{
		if(0 == queueList[i].handler && 0 == strlen(queueList[i].name))
		{
			queueList[i].handler = handlerPtr;
			strcpy(queueList[i].name, name);
			break;
		}
	}
}
void unregisterComponent(const char* name)
{
	unsigned i = 0;
	for(; i < configQUEUE_REGISTRY_SIZE; ++i)
	{
		if(0 == strcmp(queueList[i].name, name))
		{
			queueList[i].handler = 0;
			memset((void*)queueList[i].name, 0, strlen(queueList[i].name));
			break;
		}
	}
}
QueueHandle_t getHandlerPtr(const char* name)
{
	unsigned i = 0;
	for(; i < configQUEUE_REGISTRY_SIZE; ++i)
	{
		if(0 == strcmp(queueList[i].name, name))
		{
			return queueList[i].handler;
		}
	}
	return 0;
}
