#ifndef MODULE_DRTE_H_
#define MODULE_DRTE_H_

#include "drte_runtime.h"

/* Receiver ports */
#define dRTE_Read_Engine_EngineSpeed_uint16(var)  drteReadData(Engine, attr_EngineSpeed,  var);
#define dRTE_Read_Engine_EngineTemp_uint8(var)    drteReadData(Engine, attr_EngineTemp,   var);
#define dRTE_Read_Engine_EngineStruct(var)        drteReadData(Engine, attr_EngineStruct, var);

/* Sender ports */
#define dRTE_Write_Engine_EngineSpeed_uint16(var) drteWriteData(Engine, attr_EngineSpeed, &var);
#define dRTE_Write_Engine_EngineTemp_uint8(var)   drteWriteData(Engine, attr_EngineTemp,  &var);
#define dRTE_Write_MMI_KL15_uint8(var)            drteWriteData(IGNKEY, attr_KL15,        &var);
#define dRTE_Write_MMI_KL50_uint8(var)            drteWriteData(IGNKEY, attr_KL50,        &var);
#define dRTE_Write_Engine_EngineStruct(var)       drteWriteData(Engine, attr_EngineStruct,&var);
#endif
