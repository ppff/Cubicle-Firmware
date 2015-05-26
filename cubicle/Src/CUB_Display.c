#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "spi.h"
#include "CUB_Display.h"

#ifdef STANDARD_COMPILATION
#include <stdio.h>
#define MALLOC malloc
#define FREE   free
#else
#include "FreeRTOS.h"
#define MALLOC pvPortMalloc
#define FREE   vPortFree
#endif

void led_init(struct led *l, uint32_t size_x, uint32_t size_y, uint32_t size_z)
{
	l->size_x = size_x;
	l->size_y = size_y;
	l->size_z = size_z;
	l->buffer_size = size_y + 1;

	l->data   = MALLOC(sizeof(line_t *) * size_z);
	l->buffer = MALLOC(sizeof(line_t *) * size_z);
	l->tmp    = MALLOC(sizeof(line_t *) * size_z);
	for (uint32_t k=0; k<size_z; ++k) {
		l->data[k]   = MALLOC(sizeof(line_t) * size_y);
		l->buffer[k] = MALLOC(sizeof(line_t) * size_y + 1);
		l->buffer[k][l->buffer_size-1] = 1 << k;
	}

}

void led_free(struct led *l)
{
	for (uint32_t k=0; k<l->size_z; ++k) {
		FREE(l->data[k]);
		FREE(l->buffer[k]);
	}
	FREE(l->data);
	FREE(l->buffer);
}

bool in_range(struct led *l, uint32_t x, uint32_t y, uint32_t z)
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
void led_switch_on(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (in_range(l, x, y, z))
		l->data[z][l->size_y-y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void led_switch_off(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (in_range(l, x, y, z))
		if (l->data[z][l->size_y-y] & (1 << x))
			l->data[z][l->size_y-y] ^= 1 << x;
}

int led_get(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (in_range(l, x, y, z)) {
		return ((l->data[z][l->size_y-y] >> x) & 1);
	} else {
		return 0;
	}
}

void CUB_translate_x(struct led *l, int32_t x)
{
	if (x > 0) {
		for (uint32_t k=0; k<l->size_z; ++k)
			for (uint32_t j=0; j<l->size_y; ++j)
				l->data[k][l->size_y-j] <<= x;
	} else if (x < 0) {
		for (uint32_t k=0; k<l->size_z; ++k)
			for (uint32_t j=0; j<l->size_y; ++j)
				l->data[k][l->size_y-j] >>= -x;
	}
}

void CUB_translate_y(struct led *l, int32_t y)
{
	if (y > 0) {
		for (uint32_t j=l->size_y-1; j>=(uint32_t)y; --j)
			for (uint32_t k=0; k<l->size_z; ++k)
				l->data[k][l->size_y-j] = l->data[k][l->size_y-(j-y)];
		for (int32_t j=y-1; j>=0; --j)
			for (uint32_t k=0; k<l->size_z; ++k)
				l->data[k][l->size_y-j] = 0;
	} else if (y < 0) {
		for (uint32_t j=0; j<l->size_y-y; ++j)
			for (uint32_t k=0; k<l->size_z; ++k)
				l->data[k][l->size_y-j] = l->data[k][l->size_y-(j-y)];
		for (uint32_t j=l->size_y-y; j<l->size_y; ++j)
			for (uint32_t k=0; k<l->size_z; ++k)
				l->data[k][l->size_y-j] = 0;
	}
}

void CUB_translate_z(struct led *l, int32_t z)
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

void CUB_translate(struct led *l, int32_t x, int32_t y, int32_t z)
{
	if (x != 0)
		CUB_translate_x(l, x);
	if (y != 0)
		CUB_translate_y(l, y);
	if (z != 0)
		CUB_translate_z(l, z);
}

void CUB_clear(struct led *l)
{
	for (uint32_t k=0; k<l->size_z; ++k)
		memset(l->data[k], 0, l->size_y*sizeof(line_t));
}

void led_update_display(struct led *l)
{
	for (uint32_t k=0; k<l->size_z; k++)
		memcpy(l->buffer[k], l->data[k], sizeof(line_t)*l->size_y);
}

void led_display(struct led *l)
{
	for (;;) {
		for (uint32_t k=0; k<l->size_z; k++) {
			HAL_SPI_Transmit(&hspi4, l->buffer[k], l->buffer_size, 15);
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
			for (int i=0; i<40; ++i) {}
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
		}
	}
}

#ifdef STANDARD_COMPILATION
void led_print(struct led *l)
{
	for (uint32_t k=0; k<l->height; ++k) {
		for (uint32_t j=0; j<l->width; ++j) {
			line_t tmp = l->data[k][j];
			for (uint32_t i=0; i<l->length; ++i) {
				if (tmp >> i & 1)
					printf("(%u, %u, %u)\n", i, j, k);
			}
		}
	}
}
#endif
