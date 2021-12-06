#ifndef DRTE_OS_H_
#define DRTE_OS_H_

#include "drte_runtime.h"

stdReturnType SetEvent(uint8 task, uint32 event);
void GetEvent(uint8 task, uint32* event);

#endif
