/**
 * @file    : heap.h
 * @brief   : Public API
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
