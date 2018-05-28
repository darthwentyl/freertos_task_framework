#ifndef __STARTUP_STARTUP_ITEM_H__
#define __STARTUP_STARTUP_ITEM_H__

#define STARTUP_COMMAND(STATE, CREATE, INIT, RUN) {STATE, CREATE, INIT, RUN}

typedef enum
{
	NO_CREATE,
	NO_START,
	NO_RUN,
	NO_INIT,
	STARTUP_FINISH,
	END_OF_PROCEDURE
}StartupState;

typedef struct
{
	StartupState currentState;
}StartupItem;

typedef struct
{
	StartupItem* item;
	StartupState (*create)(StartupItem**);
	StartupState (*init)(StartupItem**);
	StartupState (*run)(StartupItem**);
} StartupCommand;

#endif // __STARTUP_STARTUP_ITEM_H__
