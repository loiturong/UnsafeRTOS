/**
 * @file    : kernel.h
 * @brief   : Provide Kernel Public API. Kernel will provide some incomplete data type, that
 * Application will pass this object back to Kernel API that use it. Application is
 * not supposed to know what the structure is nor could modify it.
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef kernel_H
#define kernel_H

/* -------- Include: Compiler Static Library    -------- */
#include <stdint.h>
#include <stddef.h>

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Types             	-------- */
typedef struct task_control_block_t* task_handle_t;

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
task_handle_t task_create(uintptr_t *p_array_stack, size_t stack_size, uintptr_t *p_task_entry);
void kernel_start(void);

/* -------- Function: Static Implementation     -------- */

#endif /* kernel_H */
