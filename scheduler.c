/**
 * @file    : scheduler.c
 * @brief   : scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */
#include "kernel.h"

/* -------- Include: Kernel Modules Include     -------- */
#include "scheduler.h"
#include "task.h"

#include "portable.h"

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */
typedef struct node_t {
	struct node_t *next;
	struct task_control_block_t *tcb;
} node_t;

/* -------- Objects:     Global Object          -------- */
extern struct task_control_block_t *g_p_curr_task;
extern struct task_control_block_t *g_p_prev_task;

struct task_control_block_t *g_p_first_task;
struct task_control_block_t *g_p_curr_task;
struct task_control_block_t *g_p_prev_task;

node_t *g_p_list_tail;

/* -------- Objects:     Static Obejct          -------- */
static int s_counter = 0;

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */
void kernel_start(void)
{
	sys_call();
}

/* -------- Function: Public Internal API       -------- */
int scheduler_pick_new_task(void)
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

void scheduler_register_task()
{
	if(g_p_first_task == NULL) {
		p_task->next = p_task;
		task__init_task_list(p_task);
	} else {
		p_task->next = g_p_first_task;
		g_p_prev_task->next = p_task;
		g_p_prev_task = p_task;
	}
	return;
}

/* -------- Function: Static Implementation     -------- */

