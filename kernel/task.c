/**
 * @file    : task.c
 * @brief   : task create, allocate
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdint.h>
#include "task.h"

uint32_t counter1 = 0;
uint32_t counter2 = 0;

uint32_t default_task_stack[256];
void default_task(void)
{
	for(;;);
}

uint32_t task_a_stack[256];
void task_a(void)
{
	for(;;)
		counter1++;
}

uint32_t task_b_stack[256];
void task_b(void)
{
	for(;;)
		counter2++;
}
