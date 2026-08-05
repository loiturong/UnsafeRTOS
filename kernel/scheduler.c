/**
 * @file    : scheduler.c
 * @brief   : scheduler
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "task.h"

struct TaskContext {
	uint32_t *sp;
	uint32_t CurrentContext;
}

TaskContext TaskList[3];


