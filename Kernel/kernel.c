/**
 * @file    : kernel.c
 * @brief   : kernel entry
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <Port/Include/port.h>
#include <HAL/Include/hal.h>
#include <scheduler/task.h>

uint32_t counter_a = 0;
uint32_t counter_b = 0;

char task_a_stack[256 * 4];
void task_a(void) {
	for(;;) { counter_a++; }
}

char task_b_stack[256 * 4];
void task_b(void) {
	for(;;) { counter_b++; }
}

void kernel_main()
{
	disable_int();
	early_init();
	setupException();
	// 16MHz, 1ms
	SysTick_Config(16000000, 10);
	enable_int();
	
	task_create((uintptr_t *)task_a_stack, 32 * 4, (void *)task_a);
	task_create((uintptr_t *)task_b_stack, 32 * 4, (void *)task_b);

	sys_call();

	while(1);
}


