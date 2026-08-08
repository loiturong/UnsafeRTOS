/**
 * @file    : task.c
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <heap/heap.h>
#include "task.h"

struct TaskContext *tasklisthead;
struct TaskContext *tasklisttail;
struct TaskContext *tasklistcurr;
struct TaskContext *tasklistprev;
static void context_init(stack_t *st, uintptr_t *task_entry);

static void tasklist_init(struct TaskContext *task_context)
{
	tasklisthead = task_context;
	tasklisttail = tasklisthead;
	tasklistcurr = tasklisthead;
	tasklistprev = tasklistcurr;
}

void task_create(
	uintptr_t *head,
	size_t stack_size,
	uintptr_t *task_entry
)
{
	struct TaskContext *tsk = kalloc(sizeof(struct TaskContext));
	stack_t *task_stack = &tsk->task_stack;
	stack_from_array(task_stack, head, stack_size);
	
	context_init(task_stack, task_entry);
	if(tasklisthead == NULL) {
		tsk->next = tsk;
		tasklist_init(tsk);
	} else {
		tsk->next = tasklisthead;
		tasklisttail->next = tsk;
	}
}

void context_init(stack_t *st, uintptr_t *task_entry)
{
	push_stack(st, 0x01000000);		// xPRS
	push_stack(st, (uintptr_t)task_entry);	// R15 (PC)
	push_stack(st, 0x00000000);		// R14 (LR)

	/* R0, R1, R2, R3, and R12 is "dont' care" value */
	st->pnt -= 5;

	/* Also preserve space for R4-R11 which will be poped by PendSV on context switch */
	st->pnt -= 8;
}
