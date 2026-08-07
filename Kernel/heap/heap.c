/**
 * @file    : heap.c
 * @brief   : heap to allocate to data to RAM
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define NUM_OF_BLOCK		10
#define BLOCK_SIZE		256	// 64 words size

extern char end_of_data[];

typedef struct llst {
	uintptr_t *head;
	size_t bsize;
	struct llst *next;
	struct llst *prev;
} frlst_t;

void heapinit()
{
	uintptr_t *head_pnt = (uintptr_t *)&end_of_data;
	int i = 0;
	frlst_t *block = NULL;
	frlst_t *prev_block = NULL;
	do {
		block->head = (uintptr_t *)((uintptr_t)head_pnt + sizeof(frlst_t));
		block->bsize = BLOCK_SIZE;
		block->prev = NULL;
		block->next = prev_block;
		head_pnt += sizeof(frlst_t);
		memcpy(head_pnt, block, sizeof(frlst_t));
		prev_block = block;
	} while (++i < NUM_OF_BLOCK);
}
