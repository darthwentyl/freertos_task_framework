
#include <FreeRTOSConfig.h>
#include <FreeRTOS.h>
#include <task.h>

extern void startup_boot();
extern void startup_peripheries();
extern void startup_components();

int main(void)
{
	startup_boot();
	startup_peripheries();
	startup_components();
    for(;;);
    return 0;
}

void vApplicationMallocFailedHook( void )
{
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	taskDISABLE_INTERRUPTS();
	for( ;; );
}

void vApplicationTickHook( void )
{
}
