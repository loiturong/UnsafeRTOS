/**
 * @file    : rtos_kernel.h
 * @brief   : kernel public api
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef rtos_kernel_H
#define rtos_kernel_H

#include <stdint.h>
#include <stddef.h>

void task_create(uintptr_t *head, size_t stack_size, uintptr_t *task_entry);
void kernelstart(void);

#endif /* rtos_kernel_H */
