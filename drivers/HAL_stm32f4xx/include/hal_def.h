/**
 * @file    : hal_def.h
 * @brief   : header provide common helpers
 * 
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef HAL_DEF_H
#define HAL_DEF_H

typedef enum {
	SETUP_OK = 0,
	FAILED,
} HAL_MStatus_t;

static inline void reg_set_bits(volatile uint32_t *reg, uint32_t mask) {
    *reg |= mask;
}

static inline void reg_clear_bits(volatile uint32_t *reg, uint32_t mask) {
    *reg &= ~mask;
}

static inline int reg_set_bits_wait(volatile uint32_t *reg, uint32_t mask, uint32_t timeout) {
    while (timeout--) {
        if ((*reg & mask) == mask) return 0;
    }
    return -1; /* timeout */
}

static inline int reg_get_bits(volatile uint32_t *reg, uint32_t mask) {
    int bit = *reg & mask;
    return bit;
}

#endif /* HAL_DEF_H */
