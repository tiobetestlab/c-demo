#ifndef DRTE_RUNTIME_H_
#define DRTE_RUNTIME_H_

#include "std_types.h"          /* Standard types */
#include "drte_complextypes.h"  /* Complex types  */
#include "drte.h"               /* Data indexing  */
#include "drte_os.h"            /* OS relation    */

/* Return value mactos for dRTE_ read and write actions */
#define DRTE_E_OK	   0x00u	/* Read action OK       */
#define DRTE_NO_ACTION 0x01u    /* No action was taken  */
#define DRTE_ERROR	   0xFFu	/* Error during reading */

/* Events */
#define EVENT_NONE 0x000000000u
#define EVENT_KL15 0x000000001u

/* Event function macros */
#define DRTE_SET_EVENT(task, event) SetEvent(task, event)
#define DRTE_GET_EVENT(task, event) GetEvent(task, event)
#define DRTE_CLR_EVENT(task, event) ClrEvent(task, event)


/* Default port layout */
typedef struct
{
	t_drte_data const pDataRef;
	uint16 elemSize;
}t_drte_sPort;


/* Action types */
typedef enum
{
  NOACTION = 0,
  CALLBACK = 1,
  RUNNABLE = 2,
} t_drte_actionType;


/* Callback function pointer type definition */
/*      rtn   new type          argument*/
typedef void (*t_drte_callback)(void);
typedef void (*t_drte_runnable)(void);
typedef uint32 t_drte_event;
typedef uint8  t_drte_task;

/* Structure for action configuration */
typedef struct
  {
    t_drte_actionType actionType;  /* Action type   */
    t_drte_event      event;       /* Event type    */
    t_drte_task       task;        /* Assigned task */
    t_drte_callback   pCallback;   /* Callback      */
  }t_drte_action;

/* Structure for runnable handling */
typedef struct
{
	t_drte_runnable pRunnable;
    t_drte_event    event;
} t_dRteEvent;

/* dRTE Container structure */
typedef struct
{
	const t_drte_sPort * const          pPort;       /* Port Identifier             */
	const uint8                         numDataElem; /* Index of first attribute    */
	const t_drte_action * const * const pAction;     /* Action when writing (array) */
    const uint8                         numActions;  /* Number of actions           */
} t_drte_container;



/* Prototypes to read and write functions */	
stdReturnType        drteReadData(t_drte_port port, uint8 attribute, t_drte_data pData);
stdReturnType        drteWriteData(t_drte_port port, uint8 attribute, t_drte_data pData);
static stdReturnType rteCallActions(t_drte_port port, uint8 attribute);
#endif
