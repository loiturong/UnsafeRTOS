/**
 * @file    : scheduler.c
 * @brief   : round-robin scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */
#include "kernel.h"

/* -------- Include: Kernel Modules Include     -------- */
#include "scheduler.h"

#include "portable.h"

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */
typedef struct node_t {
	struct task_control_block_t *p_tcb;
	struct node_t *next;
} node_t;

/* -------- Objects:     Global Object          -------- */
node_t *g_p_list_head;
node_t *g_p_list_tail;

node_t *g_p_task_current;
node_t *g_p_task_next;

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */
void kernel_start(void)
{
	sys_call();
}

/* -------- Function: Public Internal API       -------- */
int scheduler_pick_new_task(void)
{

	while((g_p_task_next->p_tcb->status != RUNNING)) {
		g_p_task_current = g_p_task_next;
		g_p_task_next = g_p_task_next->next;
	}

	g_p_task_current = g_p_task_next;
	g_p_task_next = g_p_task_next->next;
	return 1;
}

void scheduler_register_task(struct task_control_block_t *p_task)
{
	node_t *p_task_node = kalloc(sizeof(node_t));
	p_task_node->p_tcb = p_task;
	
	if(g_p_list_head == NULL) {
		g_p_list_head = p_task_node;
		g_p_list_tail = g_p_list_head;
		return;
	}

	g_p_list_tail->next = p_task_node;
	p_task_node->next = g_p_list_head;
	g_p_list_tail = p_task_node;
	return;
}

void scheduler_register_task_static(
		struct task_control_block_t *p_task,
		kernel_block_t *p_kernel_block)
{
	_Static_assert(
		sizeof(node_t) <= SCHEDULER_BLOCK_SIZE, 
		"Space for TaskControlBlock is too small");

	node_t *p_task_node = (node_t *)p_kernel_block->p_scheduler;

	p_task_node->p_tcb = p_task;
	
	if(g_p_list_head == NULL) {
		g_p_list_head = p_task_node;
		g_p_list_tail = g_p_list_head;
		return;
	}

	g_p_list_tail->next = p_task_node;
	p_task_node->next = g_p_list_head;
	g_p_list_tail = p_task_node;
	return;
}

/* -------- Function: Static Implementation     -------- */

