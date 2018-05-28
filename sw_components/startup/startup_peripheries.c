#define COMMAND( IS_START, INIT_FUNC ) { IS_START, INIT_FUNC }

typedef enum
{
	INIT,
	NO_INIT,
	END
}ACTION;

typedef struct
{
	ACTION action;
	void(*init)();
}InitPheripCommand;

extern void init_gpio();

InitPheripCommand init[] =
{
		COMMAND( INIT, init_gpio ),
		COMMAND( END , 0 )
};

void startup_peripheries()
{
	unsigned char i = 0;
	while( init[i].action != END )
	{
		if( init[i].action == INIT )
			init[i].init();
		++i;
	}
}

