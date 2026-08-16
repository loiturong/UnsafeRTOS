/**
 * @file    : task.c
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "kernel.h"

#include "task.h"
#include "heap.h"
#include "stack.h"

task_control_block_t *g_p_first_task;
task_control_block_t *g_p_curr_task;
task_control_block_t *g_p_prev_task;

static inline uintptr_t *context_init(uintptr_t *st, uintptr_t *p_task_entry);
static inline void tasklist_init(task_control_block_t *p_task);

task_control_block_t *task_create(
	uintptr_t *p_array_stack, 
	size_t stack_size, 
	uintptr_t *p_task_entry
)
{
	task_control_block_t *p_task = kalloc(sizeof(task_control_block_t));
	p_task->task_st = stack_create(p_array_stack, stack_size);
	
	p_task->task_st = context_init(p_task->task_st, p_task_entry);
	if(g_p_first_task == NULL) {
		p_task->next = p_task;
		tasklist_init(p_task);
	} else {
		p_task->next = g_p_first_task;
		g_p_prev_task->next = p_task;
		g_p_prev_task = p_task;
	}

	return p_task;
}

static inline void tasklist_init(task_control_block_t *p_task)
{
	g_p_first_task = p_task;
	g_p_curr_task = g_p_first_task;
	g_p_prev_task = g_p_curr_task;
}

uintptr_t *context_init(uintptr_t *st, uintptr_t *p_task_entry)
{
	*(--st) = 0x01000000;			// xPRS
	*(--st) = (uintptr_t)p_task_entry;	// PC
	*(--st) = 0x00000000;			// LR (a task return would cause Busfault here)

	/* R0, R1, R2, R3, and R12 is "dont' care" value */
	st -= 5;

	/* Also preserve space for R4-R11 which will be poped by PendSV on context switch */
	st -= 8;

	return st;
}
