#pragma  check_stack /* FreeBSD library requires code outside of the
include guard */

#include "drte_runtime.h"
//#include "std_types.h"
//Comment to create a pull request

extern const t_dRteEvent taskTable_TASK[];
extern void drteRunnableExec(t_dRteEvent runnableFunc[], t_drte_event event);
void task(void);

void task(void)
{
     uint8 event = 0;
     uint8 task  = 0;
     
     DRTE_GET_EVENT(task, &event);
     DRTE_CLR_EVENT(task, event);

     drteRunnableExec(taskTable_TASK, event);
}
