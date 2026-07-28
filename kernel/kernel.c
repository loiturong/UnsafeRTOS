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
	early_init();

	setupNVIC();

	// 16MHz, 1ms
	SysTick_Config(16000000, 1);

	while(1);
}
