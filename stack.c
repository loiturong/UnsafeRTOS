/**
 * @file    : stack.c
 * @brief   : implement topdown stack model
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stack.h"

/* 
 * Simplify stack operation by just providing the top stack,
 * Task will evaluate its stack size before use.
 */
uintptr_t *stack_from_array_v2(uintptr_t *array_head, size_t size)
{
	return array_head + size;
}
