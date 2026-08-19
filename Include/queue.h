/**
 * @file    : queue.h
 * @brief   : 
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef queue_H
#define queue_H

/* -------- Include: Compiler Static Library    -------- */
#include <stdint.h>
#include <stddef.h>

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Types             	-------- */
typedef struct {
	uintptr_t *qarray;
	size_t size;
	uintptr_t *head;
	uintptr_t *tail;
} queue_t;

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */

/* -------- Function: Public Internal API       -------- */
queue_t *queue_init_from_array(uintptr_t *p_array, size_t size);
void queue_push(queue_t *p_queue, uintptr_t item);
uintptr_t queue_pop(queue_t *p_queue);

/* -------- Function: Static Implementation     -------- */





#endif /* queue_H */
