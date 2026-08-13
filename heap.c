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

#define BLOCK_SIZE	128	// 32 words size

#ifndef KHEAP_SIZE
	#define KHEAP_SIZE	1024 * 8
#endif

extern char end_of_data[];

typedef struct node {
	uintptr_t *head;
	struct node *next;
} freelist_t;

static int heap_status = 0;	// indicate init status
freelist_t *heap;
freelist_t *htail;

static void heapinit()
{
	char *pnt = (char *)&end_of_data;
	// First block
	heap = (freelist_t *)pnt;
	heap->head = (uintptr_t *)(heap+1);
	heap->next = NULL;
	pnt += sizeof(freelist_t) + BLOCK_SIZE;

	freelist_t *block;
	freelist_t *prev = heap;

	for(int i = 0; i < (KHEAP_SIZE / BLOCK_SIZE); i++) {
		block = (freelist_t *)pnt;

		block->head = (uintptr_t *)(block+1);
		prev->next = block;

		pnt += sizeof(freelist_t) + BLOCK_SIZE;
	}
	htail = block;
	htail->next = NULL;
}

void *kalloc(size_t size)
{
	if (heap_status == 0) {
		heapinit();
		heap_status = 1;
	}
	if ((heap == NULL) || (size == 0) || (size > BLOCK_SIZE))
		return (void *)NULL;

	void *pnt = heap->head;
	heap = heap->next;
	return pnt;
}

void kfree(void *pnt)
{
	if (pnt == NULL)
		return;
	freelist_t *block = (pnt - sizeof(freelist_t));
	htail->next = block;
	htail = htail->next;
}

