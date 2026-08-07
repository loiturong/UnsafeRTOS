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
	uintptr_t *top_stack = (uintptr_t *)((uintptr_t)array + (uintptr_t)size);
	st->top = top_stack;
	st->pnt = top_stack;
	st->size = size;
	return;
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
		return (void*)NULL;
	
	void *pnt = st->pnt;
	st->pnt++;

	return pnt;
}

