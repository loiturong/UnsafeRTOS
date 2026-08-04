/**
 * @file    : kernel.c
 * @brief   : kernel entry
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include <Port/Include/port.h>
#include <HAL/Include/hal.h>

void kernel_main()
{
	disable_int();

	early_init();

	setupException();

	// 16MHz, 1ms
	SysTick_Config(16000000, 10);

	enable_int();

	while(1);
}

