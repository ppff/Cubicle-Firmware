#ifndef _CUBICLE_CONSTANTS_H_
#define _CUBICLE_CONSTANTS_H_

/*
 * 16x16x16 needs led_buffer update
 */
#define CUBE_WIDTH 9
#define SPI_TIMEOUT 100

#include "FreeRTOS.h"
#define MALLOC pvPortMalloc
#define FREE   vPortFree
#define malloc MALLOC
#define free   FREE

#endif // _CUBICLE_CONSTANTS_H_
