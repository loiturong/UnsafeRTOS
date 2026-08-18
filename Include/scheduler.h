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
#include "heap.h"
#include "task.h"

/* -------- Include: Kernel Modules Include     -------- */
void scheduler_register_task(struct task_control_block_t *p_task);
int scheduler_pick_new_task(void);

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

#endif /* SCHEDULER_H */
