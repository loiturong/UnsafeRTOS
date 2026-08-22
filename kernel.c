/**
 * @file    : kernel.c
 * @brief   : System Interface
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

/* -------- Include: Compiler Static Library    -------- */

/* -------- Include:   Public API Include       -------- */
#include "kernel.h"
#include "portable.h"
#include "scheduler.h"

/* -------- Include: Kernel Modules Include     -------- */

/* -------- 		  Define             	-------- */

/* -------- 		  Types             	-------- */

/* -------- Objects:     Global Object          -------- */

/* -------- Objects:     Static Obejct          -------- */

/* -------- Function:   Static Function         -------- */

/* -------- Function:      Public API           -------- */
void kernel_start(void) { SYS_CALL(0x00); while(1); }
void task_yield(void)	{ SYS_CALL(0x01); }
void task_delay(process_control_block_t *p_tsk, uint32_t ticks)
{
	scheduler_delayed_task(p_tsk, ticks);
	if (p_tsk == NULL)
		task_yield();
}

/* -------- Function: Public Internal API       -------- */

/* -------- Function: Static Implementation     -------- */

