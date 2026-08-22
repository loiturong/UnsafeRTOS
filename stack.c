/**
 * @file    : stack.c
 * @brief   : implement topdown stack model
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */
#include "stack.h"

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
inline uintptr_t *stack_create(uintptr_t *p_array_head, size_t size)
{
	return p_array_head + size;
}

/* -------- Function: Static Implementation     -------- */

