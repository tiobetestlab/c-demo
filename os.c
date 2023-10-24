#pragma  check_stack /* FreeBSD library requires code outside of the
include guard */

#include "drte_runtime.h"
//#include "std_types.h"
//Comment to create a pull request

/* Introduced violations */
static uint16   Violation1      = 5000u;
static uint16   Violation2      = 5000u;
static uint16   Violation3      = 5000u;
static uint16   Violation4      = 5000u;
static uint16   Violation5      = 5000u;
static uint16   Violation6      = 5000u;

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
