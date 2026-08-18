/**
 * @file    : queue.c
 * @brief   : queue implementation. As for this period.
 * This queue is designed to mainly used for schedduler.
 * Safety Feature is not implemented.
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */
#include <queue.h>
#include "heap.h"

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */
static inline int queue__is_empty(queue_t *p_queue);
static inline int queue__is_full(queue_t *p_queue);

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
queue_t *queue_init_from_array(uintptr_t *p_array, size_t size)
{
	queue_t *p_queue = kalloc(sizeof(queue_t));
	p_queue->qarray = p_array;
	p_queue->size = size;
	p_queue->head = p_array[0];
	p_queue->tail = p_array[0];

	return p_queue;
}

void queue_push(queue_t *p_queue, uintptr_t item)
{
	if (!p_queue__is_full(p_queue))
		*(p_queue->tail++) = item;
}

uintptr_t queue_pop(queue_t *p_queue)
{
	uintptr_t item = 0;
	if (!p_queue__is_empty(p_queue))
		item = *(p_queue->head++);
	return item;
}

/* -------- Function: Static Implementation     -------- */
int queue__is_empty(queue_t *p_queue)
{
	return (p_queue->tail == p_queue->head) ? 1 : 0;
}

int queue__is_full(queue_t *p_queue)
{
	return (((p_queue->tail + 1) == p_queue->head) ||
	((p_queue->tail - p_queue->head) == p_queue->size)) ? 1 : 0;
}

