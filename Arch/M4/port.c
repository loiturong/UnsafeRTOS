/**
 * @file    : port.c
 * @brief   : ARM specific
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "portable.h"

void sys_call()
{
	__asm volatile("svc 0\n");
}
