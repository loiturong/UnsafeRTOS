/**
 * @file    : stack.c
 * @brief   : implement topdown stack model
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "stack.h"

/* Kernel Public Internal API */

uintptr_t *stack_create(uintptr_t *p_array_head, size_t size)
{
	return p_array_head + size;
}
