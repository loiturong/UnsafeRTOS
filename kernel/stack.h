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

void init_stack(stack_t *st, uintptr_t *head, size_t size);
int push_stack(stack_t *st, uintptr_t item);
void *pop_stack(stack_t *st);

#endif /* STACK_H */
