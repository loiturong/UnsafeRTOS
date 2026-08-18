/**
 * @file    : heap.h
 * @brief   : Memory Allocator, implemented as fixed-size free list.
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef HEAP_H
#define HEAP_H

/* -------- Include: Compiler Static Library    -------- */
#include <stdint.h>
#include <stddef.h>

/* -------- Include:   Public API Include       -------- */

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */
void *kalloc(size_t size);
void kfree(void *pnt);

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

#endif /* HEAP_H */
