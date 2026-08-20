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
struct list {
	node_t *head;
	node_t *tail;
};

/* -------- Objects:     Global Object          -------- */
node_t *g_p_task_current;
node_t *g_p_task_next;

/* -------- Objects:     Static Obejct          -------- */
struct list s_task_list;
struct list s_wait_list;

/* -------- Function:   Static Function         -------- */
static void waitlist__create(node_t *head);
// static void waitlist__insert(node_t *item, uint32_t ticks);

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
int scheduler_pick_new_task(void)
{

	g_p_task_current = g_p_task_next;
	g_p_task_next = g_p_task_next->next;
	return 1;
}

void scheduler_register_task_static(
		process_control_block_t *p_process_block)
{
	_Static_assert(
		sizeof(node_t) <= (PROCESS_BLOCK_SIZE), 
		"Space for Scheduler + TaskControlBlock is not big enough");

	node_t *p_task_node = (node_t *)p_process_block;
	if(s_task_list.head == NULL) {
		s_task_list.head = p_task_node;
		s_task_list.tail = p_task_node;

		g_p_task_current = s_task_list.head;
		g_p_task_next = s_task_list.head;
		
		s_task_list.head->prev = s_task_list.tail;
		s_task_list.tail->next = s_task_list.head;
		return;
	}

	s_task_list.tail->next = p_task_node;
	s_task_list.head->prev = p_task_node;
	p_task_node->prev = s_task_list.tail;
	p_task_node->next = s_task_list.head;

	s_task_list.tail = p_task_node;
	return;
}

void scheduler_delayed_task(process_control_block_t *p_tsk, uint32_t ticks)
{
	node_t *p_node = (p_tsk == NULL) ? g_p_task_current : (node_t *)p_tsk;

	if (s_wait_list.head != NULL) {
		waitlist__create(p_node);
		return;
	}
	(void)p_node;
	(void)ticks;
}

/* -------- Function: Static Implementation     -------- */
inline void waitlist__create(node_t *head)
{
	s_wait_list.head = head;
	s_wait_list.tail = head;
}

/*
inline void waitlist__insert(node_t *item, uint32_t ticks)
{
	if(ticks >= s_p_wait_list->tail->p_tcb->tdelay) {
		s_p_wait_list->tail->next = item;
		item->p_tcb->tdelay = ticks - s_p_wait_list->tail->p_tcb->tdelay;
		s_p_wait_list->tail = item;
		item->next = NULL;
		return;
	}

	node_t *node = s_p_wait_list->head;
	while(node->p_tcb->tdelay < ticks) {
		ticks -= node->p_tcb->tdelay;
		node = node->next;
	}
	node = node->prev;

	item->next = node->next;
	node->next->prev = item;
	item->prev = node;
	node->next = item;
	item->p_tcb->tdelay = ticks - node->p_tcb->tdelay;
}
*/
