#include <StartupItem.h>
#include <StartupLedItem.h>
#include <StartupButtonItem.h>
#include <stm32f0xx_gpio.h>
#include <ComponentManager.h>

static StartupItem END_PROCEDURE = { END_OF_PROCEDURE };

static StartupCommand startupCommands[] =
{
		STARTUP_COMMAND( NULL, createLedItem, initLedItem, runLedItem),
		STARTUP_COMMAND( NULL, createButtonItem, initButtonItem, runButtonItem),
		STARTUP_COMMAND( &END_PROCEDURE, 0, 0, 0)
};

void create_step(StartupCommand* item);
void init_step(StartupCommand* item);
void run_step(StartupCommand* item);

void startup_components()
{
	unsigned index = 0;
	initComponentList();
	while(END_OF_PROCEDURE != startupCommands[index].item->currentState)
	{
		create_step(&startupCommands[index]);
		init_step(&startupCommands[index]);
		run_step(&startupCommands[index]);
		++index;
	}
	vTaskStartScheduler();
	while(1);
}

void create_step(StartupCommand* item)
{
	item->create(&item->item);
}

void init_step(StartupCommand* item)
{
	item->init(&item->item);
}

void run_step(StartupCommand* item)
{
	item->run(&item->item);
}
