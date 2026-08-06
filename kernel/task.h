/**
 * @file    : task.h
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stddef.h>
#include "stack.h"

// Linked-list style
struct TaskContext {
	uintptr_t *sp;
	struct TaskContext *next;
	stack_t task_stack;
};

extern struct TaskContext *tasklisthead;
extern struct TaskContext *tasklisttail;
extern struct TaskContext *tasklistcurr;

void task_create(uintptr_t *head, size_t stack_size, uintptr_t *task_entry);
void tasklist_init(void);

#endif /* TASK_H */
