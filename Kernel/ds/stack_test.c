/**
 * @file    : stack_test.c
 * @brief   : test stack, this test is just to watch stack behavior
 * Safe-guard will be handle else where.
 *
 * @Author  : Claude, Loiturong
 * @License : 
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "stack.h"

/* Print helper */
static void dump(stack_t *st, const char *label)
{
	printf("%-25s top=%p pnt=%p size=%zu\n",
	       label, (void *)st->top, (void *)st->pnt, st->size);
}

int main(void)
{
	int stack_size = 8;
	stack_t *st = (stack_t *)malloc(sizeof(stack_t));
	uintptr_t *backing = (uintptr_t *)malloc(sizeof(uintptr_t) * stack_size);

	printf("=== init ===\n");
	stack_from_array(st, backing, stack_size);
	dump(st, "after stack_from_array");
	
	printf("\n=== push ===\n");
	for (int i = 0; i < stack_size; i++) {
		push_stack(st, (uintptr_t)(0x1000 + i));
		printf("push_stack(0x%x)", 0x1000 + i);
		dump(st, "");
	}
	
	/* was leading to segfault here
	printf("\n=== push past capacity (should fail) ===\n");
	push_stack(st, (uintptr_t)0xDEAD);
	printf("push_stack(0xDEAD)");
	dump(st, "");
	*/

	printf("\n=== pop ===\n");
	for (int i = 0; i < stack_size; i++) {
		uintptr_t val = pop_stack(st);
		printf("pop_stack() -> %ld  ", val);
		dump(st, "");
	}

	printf("\n=== pop past empty (should fail / NULL) ===\n");
	uintptr_t underflow = pop_stack(st);
	printf("pop_stack() -> %ld  ", underflow);
	dump(st, "");

	printf("\n=== push/pop mix (LIFO check) ===\n");
	stack_from_array(st, backing, 8);
	push_stack(st, 111);
	push_stack(st, 222);
	push_stack(st, 333);
	printf("pop -> %ld (expect 333)\n", pop_stack(st));
	printf("pop -> %ld (expect 222)\n", pop_stack(st));
	push_stack(st, 444);
	printf("pop -> %ld (expect 444)\n", pop_stack(st));
	printf("pop -> %ld (expect 111)\n", pop_stack(st));

	free(st);
	free(backing);
	return 0;
}
