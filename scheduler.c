/**
 * @file    : scheduler.c
 * @brief   : scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "kernel.h"

#include "scheduler.h"
#include "task.h"

#include "portable.h"

extern task_control_block_t *g_p_curr_task;
extern task_control_block_t *g_p_prev_task;

static int s_counter = 0;
int picknewtask(void);

int picknewtask(void)
{
	if (s_counter >= 100)
		return 0;
	s_counter = 0;

	while((g_p_curr_task->next->status != RUNNING) && (s_counter++ < 100)) {
		g_p_prev_task = g_p_curr_task;
		g_p_curr_task = g_p_curr_task->next;
	}
	g_p_prev_task = g_p_curr_task;
	g_p_curr_task = g_p_curr_task->next;
	return 1;
}

void kernel_start(void)
{
	sys_call();
}
