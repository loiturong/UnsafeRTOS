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

typedef enum {
	RUNNING 	= 1,
	DONE		= 2,
} TaskStatus_t;

typedef struct task_node {
	uintptr_t *task_st;
	struct task_node *next;
	TaskStatus_t status; 
} TaskContext_t;

void task_create(uintptr_t *head, size_t stack_size, uintptr_t *task_entry);

#endif /* TASK_H */
