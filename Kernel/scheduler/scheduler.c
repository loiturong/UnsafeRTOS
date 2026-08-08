/**
 * @file    : scheduler.c
 * @brief   : scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "task.h"
#include <Port/Include/port.h>
#include "scheduler.h"

void startScheduler()
{
	sys_call();
}

extern struct TaskContext *tasklistcurr;
extern struct TaskContext *tasklistprev;
int picknewtask()
{
	tasklistprev = tasklistcurr;
	tasklistcurr = tasklistcurr->next;
	return 1;
	/* TODO: using some enum state to indicate this fore readability */
	// return 0;
}
