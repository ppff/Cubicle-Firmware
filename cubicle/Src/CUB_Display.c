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

void led_init(struct led *l, uint32_t length, uint32_t width, uint32_t height)
{
	l->length = length;
	l->width  = width;
	l->height = height;
	l->buffer_size = width + 1;

	l->data   = MALLOC(sizeof(line_t *) * height);
	l->buffer = MALLOC(sizeof(line_t *) * height);
	l->tmp    = MALLOC(sizeof(line_t *) * height);
	for (uint32_t k=0; k<height; ++k) {
		l->data[k]   = MALLOC(sizeof(line_t) * width);
		l->buffer[k] = MALLOC(sizeof(line_t) * width + 1);
		l->buffer[k][0] = 1 << k;
	}

}

void led_free(struct led *l)
{
	for (uint32_t k=0; k<l->height; ++k) {
		FREE(l->data[k]);
		FREE(l->buffer[k]);
	}
	FREE(l->data);
	FREE(l->buffer);
}

bool in_range(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (x < l->length && y < l->width && z < l->height) {
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
		l->data[z][y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void led_switch_off(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (in_range(l, x, y, z))
		if (l->data[z][y] & (1 << x))
			l->data[z][y] ^= 1 << x;
}

int led_get(struct led *l, uint32_t x, uint32_t y, uint32_t z)
{
	if (in_range(l, x, y, z)) {
		return ((l->data[z][y] >> x) & 1);
	} else {
		return 0;
	}
}

void CUB_translate_x(struct led *l, int32_t x)
{
	if (x > 0) {
		for (uint32_t k=0; k<l->height; ++k)
			for (uint32_t j=0; j<l->width; ++j)
				l->data[k][j] <<= x;
	} else if (x < 0) {
		for (uint32_t k=0; k<l->height; ++k)
			for (uint32_t j=0; j<l->width; ++j)
				l->data[k][j] >>= -x;
	}
}

void CUB_translate_y(struct led *l, int32_t y)
{
	if (y > 0) {
		for (uint32_t j=l->width-1; j>=(uint32_t)y; --j)
			for (uint32_t k=0; k<l->height; ++k)
				l->data[k][j] = l->data[k][j-y];
		for (int32_t j=y-1; j>=0; --j)
			for (uint32_t k=0; k<l->height; ++k)
				l->data[k][j] = 0;
	} else if (y < 0) {
		for (uint32_t j=0; j<l->width-y; ++j)
			for (uint32_t k=0; k<l->height; ++k)
				l->data[k][j] = l->data[k][j-y];
		for (uint32_t j=l->width-y; j<l->width; ++j)
			for (uint32_t k=0; k<l->height; ++k)
				l->data[k][j] = 0;
	}
}

void CUB_translate_z(struct led *l, int32_t z)
{
	for (uint32_t k=0; k<l->height; ++k)
		l->tmp[k] = l->data[k];
	for (uint32_t k=0; k<l->height; ++k) {
		int32_t ind = k-z;
		if (ind >= (int32_t)l->height)
			ind -= l->height;
		if (ind < 0)
			ind += l->height;
		l->data[k] = l->tmp[ind];
	}
	if (z > 0) {
		for (uint32_t k=0; k<(uint32_t)z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*l->width);
	} else if (z < 0) {
		for (uint32_t k=l->height-z; k<l->length; ++k)
			memset(l->data[k], 0, sizeof(line_t)*l->width);
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
	for (uint32_t k=0; k<l->height; ++k)
		memset(l->data[k], 0, l->width*sizeof(line_t));
}

void led_update_display(struct led *l)
{
	for (uint32_t k=0; k<l->height; k++)
		memcpy(l->buffer[k]+1, l->data[k], sizeof(line_t)*l->width);
}

void led_display(struct led *l)
{
	for (;;) {
		for (uint32_t k=0; k<l->height; k++) {
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
