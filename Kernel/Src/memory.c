/**
 * @file    : memory.c
 * @brief   : Implementation for memory managment setup
 *
 * @Author  : Loitruong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#include "core_cm4.h"

void mpuSetup(void)
{
    // Disable MPU to prevent MPU Fault
    MPU->CTRL = 0;
    // Checking MPU hardware support
    if ((MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos) == 0)
        return;
    // Alow Kernel full access
    MPU->CTRL |= MPU_CTRL_PRIVDEFENA_Msk;

    // Enable MPU
    MPU->CTRL |= (MPU_CTRL_ENABLE_Msk);
}
