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
#include <ds/stack.h>

// Linked-list style
struct TaskContext {
	struct TaskContext *next;
	stack_t task_stack;
};

void task_create(uintptr_t *head, size_t stack_size, uintptr_t *task_entry);

#endif /* TASK_H */
