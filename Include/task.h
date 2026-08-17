/**
 * @file    : task.h
 * @brief   : task create, manipulation
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

struct task_control_block_t {
	uintptr_t *task_st;
	struct task_control_block_t *next;
	task_status_t status; 
};

#endif /* TASK_H */
