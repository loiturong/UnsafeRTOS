/**
 * @file    : stack.h
 * @brief   : Topdown stack model 
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stddef.h>

uintptr_t *stack_create(uintptr_t *p_array_head, size_t size);

#endif /* STACK_H */
