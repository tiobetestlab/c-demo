#include "drte_runtime.h"
#include "std_types.h" /* dRTE/../Inc */

static t_drte_event enabledEvents = 0x000006660u;

t_drte_runnable Runnable_Notify(void);

/* task table */
const t_dRteEvent taskTable_TASK[]=
{
    {Runnable_Notify, EVENT_KL15}
};



stdReturnType SetEvent(uint8 task, t_drte_event event)
{
	enabledEvents |= event;
	//printf("\nSET_EVENT: %d | %d\n", enabledEvents, event);

	return 1;
}

stdReturnType ClrEvent(uint8 task, t_drte_event event)
{
	enabledEvents &= ~event;
	//printf("\nCLR_EVENT: %d | %d\n", enabledEvents, event);

	return 1;
}

void GetEvent(uint8 task, uint32* event)
{
	*event = enabledEvents;
	//printf("\nGET_EVENT: %d | %d\n", enabledEvents, *event);
}



/* Runnable executor */
void drteRunnableExec(const t_dRteEvent runnableFunc[], t_drte_event event)
{
	uint8 index = 0;
    
	if((runnableFunc[index].event & event) == runnableFunc[index].event )
	{
		runnableFunc[index].pRunnable();
	}
	else
	{
	    //printf("tsk run --> No Runnables set\n");
	}
}

/* Runnable funtions */
t_drte_runnable Runnable_Notify(void)
{
	//printf("tsk run --> Runnable executed in task\n");
}
