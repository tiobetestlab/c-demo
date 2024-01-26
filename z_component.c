//#include "std_types.h"
#include "component_drte.h"

#pragma CHECK_MISRA("666") /* Multi -                              Line comment */

//#AAA

extern void task(void);

int main(int argc, char *argv[])
{
  t_Engine EngineStruct      = { 66, /* EngineSpeed */
                                 77  /* EngineTemp  */
                               };
  uint16   EngineSpeed_local = 88;
  uint8    EngineTemp_local  = 90;
  uint8    KL15_local        = 1;
  uint8    KL50_local        = 1;
  uint8    retVal[5];
  _BOOL     commitSuicide = FALSE;
  
  while(!commitSuicide){
      
      /* Execute runnables in task */
      task();

      /* Check engine speed initial value */
      
      retVal[0] = dRTE_Read_Engine_EngineSpeed_uint16(&EngineSpeed_local);
      EngineSpeed_local = 666;
      retVal[1] = dRTE_Write_Engine_EngineSpeed_uint16(EngineSpeed_local);
      retVal[2] = dRTE_Read_Engine_EngineSpeed_uint16(&EngineSpeed_local);    

      /* Write engine speed unchanged */
      retVal[3] = dRTE_Write_Engine_EngineSpeed_uint16(EngineSpeed_local);
      retVal[4] = dRTE_Read_Engine_EngineSpeed_uint16(&EngineSpeed_local);    

      /* Introduce violations */

      /* Enable runnables */
      dRTE_Write_Engine_EngineTemp_uint8(EngineTemp_local);
      dRTE_Write_MMI_KL15_uint8(KL15_local);
      dRTE_Write_MMI_KL50_uint8(KL50_local);
      dRTE_Write_MMI_KL52_uint8(KL52_local);

      /* Execute runnables in task */
      task();
      
      task();
      
      EngineTemp_local = 80;
      dRTE_Write_Engine_EngineTemp_uint8(EngineTemp_local);
      task();
      
      task();
      
      (void)dRTE_Read_Engine_EngineStruct(&EngineStruct);
      
      EngineStruct.engineSpeed = 6666;
      EngineStruct.engineTemp  = 128;
      (void)dRTE_Write_Engine_EngineStruct(EngineStruct);
      EngineStruct.engineSpeed = 0;
      EngineStruct.engineTemp  = 0;
      (void)dRTE_Read_Engine_EngineStruct(&EngineStruct);
      
      commitSuicide = TRUE;
  }
  
  /* Keep console window open till keystroke */
  //system("PAUSE");
  return 0;
}

