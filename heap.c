/**
 * @file    : heap.c
 * @brief   : Implement fixed size freelist allocator
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <string.h>
#include <stdio.h>

#include "heap.h"

#define HEAP_BLOCK_SIZE		128	// 32 words size
#define HEAP_POOL_SIZE	1024 * 8

extern char end_of_data[];

typedef struct node {
	uintptr_t *head;
	struct node *next;
} freelist_t;

static int heap_status = 0;	// indicate init status
static freelist_t *p_heap;
static freelist_t *p_heap_end;

static void heapinit()
{
	char *pnt = (char *)&end_of_data;
	// First block
	p_heap = (freelist_t *)pnt;
	p_heap->head = (uintptr_t *)(p_heap + 1);
	p_heap->next = NULL;
	pnt += sizeof(freelist_t) + HEAP_BLOCK_SIZE;

	freelist_t *block;
	freelist_t *prev = p_heap;

	for(int i = 0; i < (HEAP_POOL_SIZE / HEAP_BLOCK_SIZE); i++) {
		block = (freelist_t *)pnt;

		block->head = (uintptr_t *)(block+1);
		prev->next = block;

		pnt += sizeof(freelist_t) + HEAP_BLOCK_SIZE;
	}
	p_heap_end = block;
	p_heap_end->next = NULL;
}

void *kalloc(size_t size)
{
	if (heap_status == 0) {
		heapinit();
		heap_status = 1;
	}
	if ((p_heap == NULL) || (size == 0) || (size > HEAP_BLOCK_SIZE))
		return (void *)NULL;

	void *pnt = p_heap->head;
	p_heap = p_heap->next;
	return pnt;
}

void kfree(void *pnt)
{
	if (pnt == NULL)
		return;
	freelist_t *p_block = (pnt - sizeof(freelist_t));
	p_heap_end->next = p_block;
	p_heap_end = p_heap_end->next;
}

