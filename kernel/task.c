/**
 * @file    : task.c
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "task.h"
#include "stack.h"

struct TaskContext *tasklisthead;
struct TaskContext *tasklisttail;
struct TaskContext *tasklistcurr;

void default_task(void)
{
	for(;;);
}

uintptr_t default_task_stack[64];
void tasklist_init()
{
	tasklisthead = (struct TaskContext *){0};
	tasklisttail = tasklisthead;
	tasklistcurr = tasklisthead;
	
	task_create(default_task_stack, 64, (void *)default_task);
	tasklisthead = tasklisthead->next;
}

static void context_init(stack_t *st, uintptr_t *task_entry);
void task_create(
	uintptr_t *head,
	size_t stack_size,
	uintptr_t *task_entry
)
{
	stack_t task_stack = init_stack(head, stack_size);
	
	struct TaskContext *tsk = {0};
	tsk->sp = task_stack.top;
	tsk->next = tasklisthead;
	tsk->task_stack = task_stack;

	context_init(&task_stack, task_entry);
	tasklisttail->next = tsk;
	tasklisttail = tsk;
}

void context_init(stack_t *st, uintptr_t *task_entry)
{
	push_stack(st, 0x01000000);		// xPRS
	push_stack(st, (uintptr_t)task_entry);	// R15 (PC)
	push_stack(st, 0x00000000);		// R14 (LR)

	/* R0, R1, R2, R3, and R12 is "dont' care" value */
	st->pnt -= 5;
}
