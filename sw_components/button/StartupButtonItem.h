#ifndef __STARTUP_BUTTON_ITEM_H__
#define __STARTUP_BUTTON_ITEM_H__

#include <StartupItem.h>

typedef struct
{
	StartupItem startupItem;
}StartupButtonItem;

StartupState createButtonItem(StartupItem** self);
StartupState initButtonItem(StartupItem** self);
StartupState runButtonItem(StartupItem** self);

#endif //__STARTUP_BUTTON_ITEM_H__
