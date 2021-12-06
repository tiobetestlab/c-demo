#ifndef DRTE_H_
#define DRTE_H_


/* Port listing */
typedef enum{
    Engine,
    XMSN,
    DRV_STRAT,
    IGNKEY,
}t_drte_port;

#define MAX_PORTS 4


/* Component attributes listing */

/* Engine attributes */
#define attr_EngineSpeed  	 0
#define attr_EngineTemp      1
#define attr_EngineStruct    2

/* Xmsn attributes */
#define attr_XmsnOutputSpeed 0
#define attr_XmsnInputSpeed  1
#define attr_XmsnDrumSpeed   2

/* Gear attributes */
#define attr_CurrentGear 	 0
#define attr_TargetGear 	 1

/* Ignition key switch attributes */
#define attr_KL15			 0
#define attr_KL50			 1

#endif
