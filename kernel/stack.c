/**
 * @file    : stack.c
 * @brief   : implement topdown stack model
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stack.h"

stack_t init_stack(uintptr_t *head, size_t size)
{
	uintptr_t *top_stack = (uintptr_t *)((uintptr_t)head + (uintptr_t)size);
	stack_t st = (stack_t) {
		.top = top_stack,
		.pnt = top_stack,
		.size = size,
	};
	return st;
}

int push_stack(stack_t *st, uintptr_t item)
{
	if((size_t)(st->top - st->pnt) >= st->size)
		return - 1;
	
	st->pnt--;
	*st->pnt = item;

	return 0;
}

void *pop_stack(stack_t *st)
{
	if((size_t)(st->top - st->pnt) == 0)
		return (void*)0;
	
	void *pnt = st->pnt;
	st->pnt++;

	return pnt;
}

