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

void task_a(void)
{
	for(;;)
		counter1++;
}

void task_b(void)
{
	for(;;)
		counter2++;
}
