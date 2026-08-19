/**
 * @file    : portable.h
 * @brief   : Architecture Portable API
 *
 * @Author  : Loiturong
 * @License : GNU GENERAL PUBLIC LICENSE
 */

#ifndef portable_H
#define portable_H

#define SYS_CALL(index)		do { \
		__asm volatile ("svc %[input]" :: [input] "i" (index) :); \
	} while(0)

#endif /* portable_H */
