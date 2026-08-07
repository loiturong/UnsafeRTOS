/**
 * @file    : heap.c
 * @brief   : heap to allocate to data to RAM
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <string.h>
#include <stdio.h>
#include "heap.h"

#define NUM_OF_BLOCK		10
#define BLOCK_SIZE		256	// 64 words size

extern char end_of_data[];

typedef enum {
	HEAP_FREE = 0,
	HEAP_USED = 1,
} heap_status_t;

typedef struct llst {
	uintptr_t *head;
	size_t bsize;
	heap_status_t status;
	struct llst *next;
	struct llst *prev;
} frlst_t;

frlst_t *heap_head;
frlst_t *heap_curr;

void heapinit()
{
	char *pnt = (char *)&end_of_data;
	heap_head = (frlst_t *)pnt;
	heap_curr = heap_head;
	frlst_t *block;
	frlst_t *prev_block = NULL;

	for(int i = 0; i < NUM_OF_BLOCK; i++) {
		block = (frlst_t *)pnt;

		block->head = (uintptr_t *)(block+1);
		block->bsize = BLOCK_SIZE;
		block->prev = prev_block;
		block->next = NULL;
		if(block->prev != NULL)
			block->prev->next = block;
		prev_block = block;
		pnt += sizeof(frlst_t) + BLOCK_SIZE;
	}
}

void *kalloc(size_t size)
{
	if (heap_head == NULL)
		heapinit();
	if ((size == 0) || (size > BLOCK_SIZE))
		return (void *)NULL;
	
	while(heap_curr) {
		if (heap_curr->status != HEAP_FREE) {
			heap_curr = heap_curr->next;
			continue;
		}
		void *pnt = heap_curr->head;
		heap_curr = heap_curr->next;
		heap_curr->status != HEAP_USED;
		return pnt;
	}

	return (void *)NULL;
}

void kfree(void *pnt)
{
	if (pnt == NULL)
		return;
	frlst_t *header = (pnt - sizeof(frlst_t));
	header->status = HEAP_FREE;
	heap_curr = header;
	pnt = NULL;
}

