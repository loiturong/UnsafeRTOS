/**
 * @file    : scheduler.c
 * @brief   : scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "task.h"
#include "scheduler.h"
#include "rtos_kernel.h"
#include "portable.h"

extern TaskContext_t *tasklistcurr;
extern TaskContext_t *tasklistprev;
int picknewtask(void);
int picknewtask(void)
{
	tasklistprev = tasklistcurr;
	tasklistcurr = tasklistcurr->next;
	return 1;
	/* TODO: using some enum state to indicate this fore readability */
	// return 0;
}

void kernelstart(void)
{
	sys_call();
}
