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

typedef struct {
	uintptr_t *top;
	uintptr_t *pnt;
	size_t size;
} stack_t;

void stack_from_array(stack_t *st, uintptr_t *array, size_t size);
void push_stack(stack_t *st, uintptr_t item);
uintptr_t pop_stack(stack_t *st);

uintptr_t *stack_from_array_v2(uintptr_t *array_head, size_t size);

#endif /* STACK_H */
