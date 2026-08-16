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

typedef enum {
	RUNNING 	= 1,
	DONE		= 2,
} task_status_t;

typedef struct task_node {
	uintptr_t *task_st;
	struct task_node *next;
	task_status_t status; 
} task_control_block_t;

#endif /* TASK_H */
