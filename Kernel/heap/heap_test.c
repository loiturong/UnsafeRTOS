/**
 * @file    : heap_test.c
 * @brief   : test for heap implementation on host mahcine
 *
 * @Author  : Claude
 * @License : 
 */

#include <stdio.h>
#include <string.h>
#include "heap.h"

#define NUM_OF_BLOCK		10
#define BLOCK_SIZE		256	// 64 words size

#define SIM_HEAP_SIZE	4096
char end_of_data[SIM_HEAP_SIZE];
//char end_of_data[] = fake_heap[0];

static void print_ptr(const char *label, void *p)
{
	printf("%-25s -> %p\n", label, p);
}

int main(void)
{
	printf("=== basic alloc ===\n");
	void *a = kalloc(16);
	print_ptr("kalloc(16)", a);
	
	void *b = kalloc(64);
	print_ptr("kalloc(64)", b);

	void *c = kalloc(BLOCK_SIZE);
	print_ptr("kalloc(BLOCK_SIZE)", c);

	printf("\n=== edge cases ===\n");
	void *zero = kalloc(0);
	print_ptr("kalloc(0)", zero);

	void *big = kalloc(BLOCK_SIZE + 1);
	print_ptr("kalloc(BLOCK_SIZE+1)", big);

	printf("\n=== write test ===\n");
	if (a) {
		memset(a, 0xAA, 16);
		printf("wrote 16 bytes to a, a[0]=0x%02x a[15]=0x%02x\n",
		       ((unsigned char *)a)[0], ((unsigned char *)a)[15]);
	}
	if (b) {
		memset(b, 0xAB, 32);
		printf("wrote 16 bytes to b, b[0]=0x%02x b[27]=0x%02x\n",
		       ((unsigned char *)b)[0], ((unsigned char *)b)[27]);
	}

	printf("\n=== exhaustion: alloc until NULL ===\n");
	void *ptrs[NUM_OF_BLOCK + 2];
	int i;
	for (i = 0; i < NUM_OF_BLOCK + 2; i++) {
		ptrs[i] = kalloc(8);
		printf("kalloc(8) #%2d -> %p\n", i, ptrs[i]);
	}

	printf("\n=== free + realloc ===\n");
	print_ptr("freeing ptrs[0]", ptrs[0]);
	kfree(ptrs[0]);

	void *reused = kalloc(8);
	print_ptr("kalloc(8) after free", reused);

	printf("\n=== free all (cleanup) ===\n");
	for (i = 0; i < NUM_OF_BLOCK + 2; i++) {
		if (ptrs[i]) {
			kfree(ptrs[i]);
			printf("freed ptrs[%d] = %p\n", i, ptrs[i]);
		}
	}

	return 0;
}
