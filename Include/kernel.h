/**
 * @file    : kernel.h
 * @brief   : kernel public api
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef rtos_kernel_H
#define rtos_kernel_H

#include <stdint.h>
#include <stddef.h>

#include "task.h"

task_control_block_t *task_create(uintptr_t *p_array_stack, size_t stack_size, uintptr_t *p_task_entry);
void kernel_start(void);

#endif /* rtos_kernel_H */
