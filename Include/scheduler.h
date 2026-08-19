/**
 * @file    : scheduler.h
 * @brief   : 
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */
#include "kernel.h"
#include "heap.h"
#include "task.h"

/* -------- Include: Kernel Modules Include     -------- */
void scheduler_register_task(struct task_control_block_t *p_task);
void scheduler_register_task_static(struct task_control_block_t *p_task, 
		kernel_handle_t *p_kernel_block);
int scheduler_pick_new_task(void);

/* -------- 		  Types             	-------- */
typedef struct node_t {
	struct task_control_block_t *p_tcb;
	struct node_t *next;
	struct node_t *prev;
} node_t;

/* -------- Objects:     Global Object          -------- */
extern node_t *g_p_task_current;
extern node_t *g_p_task_next;

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

#endif /* SCHEDULER_H */
