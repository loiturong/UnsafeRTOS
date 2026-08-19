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

/* -------- 		  Define             	-------- */
#define WORD_SIZE(x)			(x * 4)
#define TASK_CONTROL_BLOCK_SIZE		WORD_SIZE(4)
#define SCHEDULER_BLOCK_SIZE		WORD_SIZE(4)

/* -------- 		  Types             	-------- */
typedef struct task_control_block_t* task_handle_t;
typedef struct {
	uint8_t p_task_control[TASK_CONTROL_BLOCK_SIZE];
	uint8_t p_scheduler[SCHEDULER_BLOCK_SIZE];
} __attribute__((aligned(sizeof(uintptr_t)))) kernel_handle_t;

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
void task_create_static(kernel_handle_t *p_task_block, uintptr_t *p_array_stack, 
		size_t stack_size, uintptr_t *p_task_entry);
void kernel_start(void);

/* -------- Function: Static Implementation     -------- */

#endif /* kernel_H */
