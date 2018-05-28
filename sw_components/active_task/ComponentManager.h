#ifndef __ACTIVE_TASK_COMPONENT_MANAGER_H__
#define __ACTIVE_TASK_COMPONENT_MANAGER_H__

#include <FreeRTOSConfig.h>
#include <FreeRTOS.h>
#include <queue.h>

void initComponentList();
void registerComponent(const char* name, QueueHandle_t handlerPtr);
void unregisterComponent(const char* name);
QueueHandle_t getHandlerPtr(const char* name);

#endif // __ACTIVE_TASK_COMPONENT_MANAGER_H__
