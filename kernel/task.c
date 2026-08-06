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
static void context_init(stack_t *st, uintptr_t *task_entry);

void default_task(void)
{
	for(;;);
}

// Static init
struct TaskContext *default_task_context;
uintptr_t default_task_stack_array[64];
stack_t *default_task_stack;
void tasklist_init()
{
	init_stack(default_task_stack, default_task_stack_array, 64);
	
	default_task_context->next = default_task_context;
	default_task_context->task_stack = default_task_stack;

	context_init(default_task_stack, (void *)default_task);
	tasklisthead = default_task_context;
	tasklisttail = tasklisthead;
	tasklistcurr = tasklisthead;
}

/* Fix this latter
void task_create(
	uintptr_t *head,
	size_t stack_size,
	uintptr_t *task_entry
)
{
	init_stack(task_stack, head, stack_size);
	
	struct TaskContext *tsk = {0};
	tsk->next = tasklisthead;
	tsk->task_stack = task_stack;

	context_init(task_stack, task_entry);
	tasklisttail->next = tsk;
}
*/
void context_init(stack_t *st, uintptr_t *task_entry)
{
	push_stack(st, 0x01000000);		// xPRS
	push_stack(st, (uintptr_t)task_entry);	// R15 (PC)
	push_stack(st, 0x00000000);		// R14 (LR)

	/* R0, R1, R2, R3, and R12 is "dont' care" value */
	st->pnt -= 5;
}
