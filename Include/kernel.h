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

#include <stdint.h>
#include <stddef.h>

typedef struct task_control_block_t* task_handle_t;

task_handle_t task_create(uintptr_t *p_array_stack, size_t stack_size, uintptr_t *p_task_entry);
void kernel_start(void);

#endif /* kernel_H */
