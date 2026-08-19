/**
 * @file    : task.h
 * @brief   : task create, manipulation
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef TASK_H
#define TASK_H

/* -------- Include: Compiler Static Library    -------- */
#include <stdint.h>
#include <stddef.h>

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Types             	-------- */
typedef enum {
	RUNNING 	= 1,
	DONE		= 2,
} task_status_t;

struct task_control_block_t {
	uintptr_t *task_st;
	struct task_control_block_t *next;
	task_status_t status; 
	uint32_t tick_delayed;
};

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

#endif /* TASK_H */
