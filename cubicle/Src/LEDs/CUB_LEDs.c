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

void CUB_LEDs_init(CUB_LEDs *l, uint32_t size_x, uint32_t size_y, uint32_t size_z)
{
	l->size_x = size_x;
	l->size_y = size_y;
	l->size_z = size_z;
	l->buffer_size = size_y + 1;

	l->data   = MALLOC(sizeof(line_t *) * size_z);
	l->buffer = MALLOC(sizeof(line_t *) * size_z);
	l->tmp    = MALLOC(sizeof(line_t *) * size_z);
	l->pointer_to_data   = MALLOC(sizeof(line_t) * size_y     * size_z);
	l->pointer_to_buffer = MALLOC(sizeof(line_t) * (size_y+1) * size_z);
	for (uint32_t k=0; k<size_z; ++k) {
		l->data[k]   = l->pointer_to_data   + size_y     * k;
		l->buffer[k] = l->pointer_to_buffer + (size_y+1) * k;
		l->buffer[k][l->buffer_size-1] = 1 << k;
	}
}

void CUB_LEDs_free(CUB_LEDs *l)
{
	FREE(l->pointer_to_data);
	FREE(l->pointer_to_buffer);
}

bool CUB_LEDs_in_range(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (x < l->size_x && y < l->size_y && z < l->size_z) {
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
	if (CUB_LEDs_in_range(l, x, y, z))
		l->data[z][l->size_y-1-y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void CUB_LEDs_switch_off(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (CUB_LEDs_in_range(l, x, y, z))
		if (l->data[z][l->size_y-1-y] & (1 << x))
			l->data[z][l->size_y-1-y] ^= 1 << x;
}

int CUB_LEDs_get(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (CUB_LEDs_in_range(l, x, y, z)) {
		return ((l->data[z][l->size_y-1-y] >> x) & 1);
	} else {
		return 0;
	}
}

void CUB_LEDs_translate_x(CUB_LEDs *l, int32_t x)
{
	if (x > 0) {
		for (uint32_t k=0; k<l->size_z; ++k)
			for (uint32_t j=0; j<l->size_y; ++j)
				l->data[k][l->size_y-1-j] <<= x;
	} else if (x < 0) {
		for (uint32_t k=0; k<l->size_z; ++k)
			for (uint32_t j=0; j<l->size_y; ++j)
				l->data[k][l->size_y-1-j] >>= -x;
	}
}

void CUB_LEDs_translate_y(CUB_LEDs *l, int32_t y)
{
	if (y > 0) {
		for (uint32_t k=0; k<l->size_z; ++k) {
			for (uint32_t j=0; j<l->size_y-y; ++j)
				l->data[k][j] = l->data[k][j+y];
			for (uint32_t j=l->size_y-y; j<l->size_y; ++j)
				l->data[k][j] = 0;
		}
	} else if (y < 0) {
		for (uint32_t k=0; k<l->size_z; ++k) {
			for (uint32_t j=0; j<l->size_y+y; ++j)
				l->data[k][l->size_y-1-j] = l->data[k][l->size_y-1-j+y];
			for (uint32_t j=l->size_y+y; j<l->size_y; ++j)
				l->data[k][l->size_y-1-j] = 0;
		}
	}
}

void CUB_LEDs_translate_z(CUB_LEDs *l, int32_t z)
{
	for (uint32_t k=0; k<l->size_z; ++k)
		l->tmp[k] = l->data[k];
	for (uint32_t k=0; k<l->size_z; ++k) {
		int32_t ind = k-z;
		if (ind >= (int32_t)l->size_z)
			ind -= l->size_z;
		if (ind < 0)
			ind += l->size_z;
		l->data[k] = l->tmp[ind];
	}
	if (z > 0) {
		for (uint32_t k=0; k<(uint32_t)z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*l->size_y);
	} else if (z < 0) {
		for (uint32_t k=l->size_z-z; k<l->size_z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*l->size_y);
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
	for (uint32_t k=0; k<l->size_z; ++k)
		memset(l->data[k], 0, l->size_y*sizeof(line_t));
}

#ifndef STANDARD_COMPILATION
void CUB_LEDs_update_display(CUB_LEDs *l)
{
	for (uint32_t k=0; k<l->size_z; k++)
		memcpy(l->buffer[k], l->data[k], sizeof(line_t)*l->size_y);
}

void CUB_LEDs_display(CUB_LEDs *l)
{
	for (;;) {
		for (uint32_t k=0; k<l->size_z; k++) {
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
	for (uint32_t k=0; k<l->size_z; ++k) {
		for (uint32_t j=0; j<l->size_y; ++j) {
			line_t tmp = l->data[k][l->size_y-1-j];
			for (uint32_t i=0; i<l->size_x; ++i) {
				if (tmp >> i & 1)
					printf("(%u, %u, %u)\n", i, j, k);
			}
		}
	}
}
#endif
