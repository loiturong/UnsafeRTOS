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
struct {
	node_t *p_head;
	node_t *p_tail;
} list_t;

/* -------- Objects:     Global Object          -------- */
node_t *g_p_task_current;
node_t *g_p_task_next;

/* -------- Objects:     Static Obejct          -------- */
node_t *s_p_list_head;
node_t *s_p_list_tail;

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
int scheduler_pick_new_task(void)
{

	g_p_task_current = g_p_task_next;
	g_p_task_next = g_p_task_next->next;
	return 1;
}

void scheduler_register_task(struct task_control_block_t *p_task)
{
	node_t *p_task_node = kalloc(sizeof(node_t));
	p_task_node->p_tcb = p_task;
	
	if(s_p_list_head == NULL) {
		s_p_list_head = p_task_node;
		s_p_list_tail = s_p_list_head;
		return;
	}

	s_p_list_tail->next = p_task_node;
	p_task_node->next = s_p_list_head;
	s_p_list_tail = p_task_node;
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
	
	if(s_p_list_head == NULL) {
		s_p_list_head = p_task_node;
		s_p_list_tail = s_p_list_head;
		g_p_task_current = s_p_list_head;
		g_p_task_next = s_p_list_head;
		return;
	}

	s_p_list_tail->next = p_task_node;
	p_task_node->next = s_p_list_head;
	s_p_list_tail = p_task_node;
	return;
}

/* -------- Function: Static Implementation     -------- */

