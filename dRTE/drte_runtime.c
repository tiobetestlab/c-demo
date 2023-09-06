#include "drte_runtime.h"

/* Introduced violations */
static uint16   Violation1      = 5000u;
static uint16   Violation2      = 5000u;
static uint16   Violation3      = 5000u;
static uint16   Violation4      = 5000u;
static uint16   Violation5      = 5000u;

extern const t_drte_container drte_container[];

stdReturnType drteReadData(t_drte_port port, uint8 attribute, void* pData){

     stdReturnType retVal;
          
    if(pData != NULL){
         retVal = DRTE_E_OK;
     }else{
         retVal = DRTE_ERROR;
     }
     return retVal;
}


stdReturnType drteWriteData(t_drte_port port, uint8 attribute, void* pData)
{
  stdReturnType retVal = DRTE_E_OK;
  return retVal;
}


static stdReturnType rteCallActions(t_drte_port port, uint8 attribute)
{
  uint8               index = 666;
  stdReturnType       retVal;
  t_drte_action const* pAction;

  retVal = DRTE_E_OK;

  /* API only available in run state */
  //if (RTE_STATE_RUN == currentState)
  //{
      /* get actions for 1..n receiver */
      for (index = 0; index < drte_container[port].numActions; index++){
          
          pAction = &(((drte_container[port].pAction)[index])[attribute]);

          switch (pAction->actionType){
              case NOACTION:
                   /* Do Nothing */
                   break;
              case CALLBACK:
                     pAction->pCallback();
                   break;
              case RUNNABLE:
                   retVal = DRTE_SET_EVENT(pAction->task, pAction->event);
                   break;
              default:
                   //retVal = RTE_E_COMMS_ERROR;
                   break;
          } /* end Switch */
        } /* end for */
  //} /* end if(RTE_STATE_RUN == currentState) */

  return retVal;
}
