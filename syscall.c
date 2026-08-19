/**
 * @file    : syscall.c
 * @brief   : system call
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */
#include "kernel.h"
#include "portable.h"
#include "syscall.h"

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */
void kernel_start() 
{ 
	// Syscall is expected to return, so put an infinte loop here to wait for systick
	SYS_CALL(KERNEL_START);
	while (1);
}

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

