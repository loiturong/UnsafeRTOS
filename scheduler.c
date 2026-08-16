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
	int counter = 0;
	while((tasklistcurr->next->status != RUNNING) && (counter++ < 100)) {
		tasklistprev = tasklistcurr;
		tasklistcurr = tasklistcurr->next;
	}
	if (counter >= 100)
		return 0;
	tasklistprev = tasklistcurr;
	tasklistcurr = tasklistcurr->next;
	return 1;
}

void kernelstart(void)
{
	sys_call();
}
