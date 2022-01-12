#include "drte_runtime.h"  		 /* Includes all variables of a module */
#include "drte_os.h" /* Just to mess with include relatons */

#define NO_ACTION 0u

/* Action Callback Functions */
extern void ICE_NotifyCallSpeed(void);
extern void ICE_NotifyCallTemp(void);
extern void ICE_KL15Change_Callback(void);
extern void ICE_KL50Change_Callback(void);
extern void MMI_KL15Change_Callback(void);

/*******************/
/* DATA DEFINITION */
/*******************/
static uint16   EngineSpeed	    = 5000u;
static int8     EngineTemp      = 800u;
static t_Engine EngineStruct    = {5000u, 80u};
static uint16   XmsnOutputSpeed = 3000u;
static uint16   XmsnInputSpeed  = 5000u;
static uint16   XmsnDrumSpeed	= 4000u;
static uint8    CurrentGear     = 2u;
static uint8    TargetGear      = 3u;
static uint8    KL15		    = 0u;
static uint8    KL50		    = 0u;

/*******************/
/* PORT DEFINITION */
/*******************/
static const t_drte_sPort port_Engine[]=
{
	{(uint16*)  &EngineSpeed,  sizeof(EngineSpeed)},
	{(int8*)    &EngineTemp,   sizeof(EngineTemp)},
	{(t_Engine*)&EngineStruct, sizeof(EngineStruct)}
};

static const t_drte_sPort port_XMSN[]=
{
	{(uint16*)&XmsnOutputSpeed, sizeof(XmsnOutputSpeed)},
	{(uint16*)&XmsnInputSpeed,  sizeof(XmsnInputSpeed) },
	{(uint16*)&XmsnDrumSpeed,   sizeof(XmsnDrumSpeed)  }
};

static const t_drte_sPort port_DRV_STRAT[]=
{
	{(uint8*)&CurrentGear,     sizeof(CurrentGear)},
	{(uint8*)&TargetGear,      sizeof(TargetGear)}
};

static const t_drte_sPort port_IgnKey[]=
{
	{(uint8*)&KL15,     sizeof(KL15)},
	{(uint8*)&KL50,     sizeof(KL50)}
};



/************************/
/* ACTION CONFIGURATION */
/************************/

/*************************************************************
 ICE actions
 *************************************************************/
static const t_drte_action ICE_EngineAction[]=
{
	/* Element               Type      Event        Task  Function               */
	/* attr_EngineSpeed  */ {CALLBACK, NULL,        0,    ICE_NotifyCallSpeed},
	/* attr_EngineTemp   */ {RUNNABLE, EVENT_KL15,  0,    NULL},
	/* attr_EngineStruct */ {NOACTION, NULL,        0,    NULL}
};

static const t_drte_action *const action_Engine[]=
{
    ICE_EngineAction
};
/*************************************************************/

/*************************************************************
 KEY actions
 *************************************************************/
static const t_drte_action ICE_KeyOn[]=
{
    /* Element       Type      Event  Task  Function               */
	/* attr_KL15 */ {CALLBACK, NULL,  0,    ICE_KL15Change_Callback},
	/* attr_KL50 */ {CALLBACK, NULL,  0,    ICE_KL50Change_Callback}
};

static const t_drte_action MMI_KeyOn[]=
{  
	/* Element       Type      Event  Task  Function               */
	/* attr_KL15 */ {CALLBACK, NULL,  0,    MMI_KL15Change_Callback},
	/* attr_KL50 */ {NOACTION, NULL,  0,    NULL}
};

static const t_drte_action *const action_IgnKey[]=
{ 
    ICE_KeyOn,
    MMI_KeyOn
};
/*************************************************************/


/*******************/
/* PORT CONTAINER  */
/*******************/
const t_drte_container drte_container[MAX_PORTS]=
{
    /* port nr    Port name,      index,   action,        number of actions*/
	/* port 0 */ {port_Engine,    0,       action_Engine, 1},
	/* port 1 */ {port_XMSN,      3,       NO_ACTION,     0},
	/* port 2 */ {port_DRV_STRAT, 6,       NO_ACTION,     0},
	/* port 3 */ {port_IgnKey,    8,       action_IgnKey, 2}
};
