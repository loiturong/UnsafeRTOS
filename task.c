/**
 * @file    : task.c
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "heap.h"
#include "task.h"

TaskContext_t *tasklisthead;
TaskContext_t *tasklistcurr;
TaskContext_t *tasklistprev;

static uintptr_t *context_init(uintptr_t *st, uintptr_t *task_entry);

static void tasklist_init(TaskContext_t *task_context)
{
	tasklisthead = task_context;
	tasklistcurr = tasklisthead;
	tasklistprev = tasklistcurr;
}

void task_create(uintptr_t *head, size_t stack_size, uintptr_t *task_entry)
{
	TaskContext_t *tsk = kalloc(sizeof(TaskContext_t));
	tsk->task_st = stack_from_array_v2(head, stack_size);
	
	tsk->task_st = context_init(tsk->task_st, task_entry);
	if(tasklisthead == NULL) {
		tsk->next = tsk;
		tasklist_init(tsk);
	} else {
		tsk->next = tasklisthead;
		tasklistprev->next = tsk;
		tasklistprev = tsk;
	}
}

uintptr_t *context_init(uintptr_t *st, uintptr_t *task_entry)
{
	*(--st) = 0x01000000;			// xPRS
	*(--st) = (uintptr_t)task_entry;	// PC
	*(--st) = 0x00000000;			// LR (a task return would cause Busfault here)

	/* R0, R1, R2, R3, and R12 is "dont' care" value */
	st -= 5;

	/* Also preserve space for R4-R11 which will be poped by PendSV on context switch */
	st -= 8;

	return st;
}
