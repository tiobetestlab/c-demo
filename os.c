#pragma  check_stack /* FreeBSD library requires code outside of the
include guard */

#include "drte_runtime.h"
//#include "std_types.h"

extern const t_dRteEvent taskTable_TASK[];
extern void drteRunnableExec(t_dRteEvent runnableFunc[], t_drte_event event);
void task(void);

void task(void)
{
     uint32 event    = 666;
     uint8  task     = 636;
     
     DRTE_GET_EVENT(task, &event);
     DRTE_CLR_EVENT(task, event);

     drteRunnableExec(taskTable_TASK, event);
}
