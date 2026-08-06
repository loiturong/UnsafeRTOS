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
	tasklist_init();
	sys_call();
}

void picknexttask()
{
	tasklistcurr = tasklistcurr->next;
}
