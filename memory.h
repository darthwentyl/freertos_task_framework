#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <FreeRTOSConfig.h>
#include <FreeRTOS.h>
#include <task.h>

// Use FreeRtos heap allocator
#define malloc(size) pvPortMalloc(size)
#define free(ptr) pvPortFree(ptr)

#endif // __MEMORY_H__
