/**
 * @file    : stack.c
 * @brief   : implement topdown stack model
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stack.h"

void stack_from_array(stack_t *st, uintptr_t *array, size_t size)
{
	uintptr_t *top_stack = array + size;
	st->top = top_stack;
	st->pnt = top_stack;
	st->size = size;
	return;
}

void push_stack(stack_t *st, uintptr_t item)
{
	*(--st->pnt) = item;
}

uintptr_t pop_stack(stack_t *st)
{
	return *(st->pnt++);
}

/* 
 * Simplify stack operation by just providing the top stack,
 * Task will evaluate its stack size before use.
 */
uintptr_t *stack_from_array_v2(uintptr_t *array_head, size_t size)
{
	return array_head + size;
}
