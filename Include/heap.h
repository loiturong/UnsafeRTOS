/**
 * @file    : heap.h
 * @brief   : Memory Allocator, implemented as fixed-size free list.
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>
#include <stddef.h>

void *kalloc(size_t size);
void kfree(void *pnt);

#endif /* HEAP_H */
