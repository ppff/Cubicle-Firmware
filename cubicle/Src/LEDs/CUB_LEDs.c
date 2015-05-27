#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "LEDs/CUB_LEDs.h"

#ifdef STANDARD_COMPILATION
#include <stdio.h>
#define MALLOC malloc
#define FREE   free
#else
#include "FreeRTOS.h"
#include "spi.h"
#define MALLOC pvPortMalloc
#define FREE   vPortFree
#endif

void CUB_LEDs_init(CUB_LEDs *l)
{
	l->data   = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->buffer = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->tmp    = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->pointer_to_data   = MALLOC(sizeof(line_t) * SIZE_Y     * SIZE_Z);
	l->pointer_to_buffer = MALLOC(sizeof(line_t) * (SIZE_Y+1) * SIZE_Z);
	for (uint32_t k=0; k<SIZE_X; ++k) {
		l->data[k]   = l->pointer_to_data   + SIZE_Y     * k;
		l->buffer[k] = l->pointer_to_buffer + (SIZE_Z+1) * k;
		l->buffer[k][SIZE_Y] = 1 << k;
	}
}

void CUB_LEDs_free(CUB_LEDs *l)
{
	FREE(l->pointer_to_data);
	FREE(l->pointer_to_buffer);
}

bool CUB_LEDs_in_range(uint32_t x, uint32_t y, uint32_t z)
{
	if (x < SIZE_X && y < SIZE_Y && z < SIZE_Z) {
		return true;
	} else {
		return false;
	}
}

/**
 * line: 0000010001
 * mask: 0000000100
 * or:   0000010101 <= LED on
 */
void CUB_LEDs_switch_on(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (CUB_LEDs_in_range(x, y, z))
		l->data[z][SIZE_Y-1-y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void CUB_LEDs_switch_off(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (CUB_LEDs_in_range(x, y, z))
		if (l->data[z][SIZE_Y-1-y] & (1 << x))
			l->data[z][SIZE_Y-1-y] ^= 1 << x;
}

int CUB_LEDs_get(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (CUB_LEDs_in_range(x, y, z)) {
		return ((l->data[z][SIZE_Y-1-y] >> x) & 1);
	} else {
		return 0;
	}
}

void CUB_LEDs_translate_x(CUB_LEDs *l, int32_t x)
{
	if (x > 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k)
			for (uint32_t j=0; j<SIZE_Y; ++j)
				l->data[k][SIZE_Y-1-j] <<= x;
	} else if (x < 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k)
			for (uint32_t j=0; j<SIZE_Y; ++j)
				l->data[k][SIZE_Y-1-j] >>= -x;
	}
}

void CUB_LEDs_translate_y(CUB_LEDs *l, int32_t y)
{
	if (y > 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k) {
			for (uint32_t j=0; j<(uint32_t)(SIZE_Y-y); ++j)
				l->data[k][j] = l->data[k][j+y];
			for (uint32_t j=SIZE_Y-y; j<SIZE_Y; ++j)
				l->data[k][j] = 0;
		}
	} else if (y < 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k) {
			for (uint32_t j=0; j<(uint32_t)(SIZE_Y+y); ++j)
				l->data[k][SIZE_Y-1-j] = l->data[k][SIZE_Y-1-j+y];
			for (uint32_t j=SIZE_Y+y; j<SIZE_Y; ++j)
				l->data[k][SIZE_Y-1-j] = 0;
		}
	}
}

void CUB_LEDs_translate_z(CUB_LEDs *l, int32_t z)
{
	for (uint32_t k=0; k<SIZE_Z; ++k)
		l->tmp[k] = l->data[k];
	for (uint32_t k=0; k<SIZE_Z; ++k) {
		int32_t ind = k-z;
		if (ind >= (int32_t)SIZE_Z)
			ind -= SIZE_Z;
		if (ind < 0)
			ind += SIZE_Z;
		l->data[k] = l->tmp[ind];
	}
	if (z > 0) {
		for (uint32_t k=0; k<(uint32_t)z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*SIZE_Y);
	} else if (z < 0) {
		for (uint32_t k=SIZE_Z-z; k<SIZE_Z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*SIZE_Y);
	}
}

void CUB_LEDs_translate(CUB_LEDs *l, int32_t x, int32_t y, int32_t z)
{
	if (x != 0)
		CUB_LEDs_translate_x(l, x);
	if (y != 0)
		CUB_LEDs_translate_y(l, y);
	if (z != 0)
		CUB_LEDs_translate_z(l, z);
}

void CUB_LEDs_clear(CUB_LEDs *l)
{
	for (uint32_t k=0; k<SIZE_Z; ++k)
		memset(l->data[k], 0, SIZE_Y*sizeof(line_t));
}

#ifndef STANDARD_COMPILATION
void CUB_LEDs_update_display(CUB_LEDs *l)
{
	for (uint32_t k=0; k<SIZE_Z; k++)
		memcpy(l->buffer[k], l->data[k], sizeof(line_t)*SIZE_Y);
}

void CUB_LEDs_display(CUB_LEDs *l)
{
	for (;;) {
		for (uint32_t k=0; k<SIZE_Z; k++) {
			HAL_SPI_Transmit(&hspi4, (uint8_t *)l->buffer[k], l->buffer_size*2, 15);
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
			for (int i=0; i<40; ++i) {}
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
		}
	}
}
#endif

#ifdef STANDARD_COMPILATION
void CUB_LEDs_print(CUB_LEDs *l)
{
	for (uint32_t k=0; k<SIZE_Z; ++k) {
		for (uint32_t j=0; j<SIZE_Y; ++j) {
			line_t tmp = l->data[k][SIZE_Y-1-j];
			for (uint32_t i=0; i<SIZE_X; ++i) {
				if (tmp >> i & 1)
					printf("(%u, %u, %u)\n", i, j, k);
			}
		}
	}
}
#endif
