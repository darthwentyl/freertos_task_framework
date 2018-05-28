#ifndef __STARTUP_LED_ITEM_H__
#define __STARTUP_LED_ITEM_H__

#include <StartupItem.h>
#include <LedActiveTask.h>

typedef struct
{
	StartupItem startupItem;
	LedActiveTask ledPC8;
	LedActiveTask ledPC9;
}StartupLedItem;

StartupState createLedItem(StartupItem** self);
StartupState initLedItem(StartupItem** self);
StartupState runLedItem(StartupItem** self);

#endif //__STARTUP_LED_ITEM_H__
