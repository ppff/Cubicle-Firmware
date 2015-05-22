#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "CUB_Display.h"

void led_init(struct led *l, uint32_t length, uint32_t width, uint32_t height)
{
	l->length = length;
	l->width  = width;
	l->height = height;

	l->data   = malloc(sizeof(line_t *) * height);
	l->buffer = malloc(sizeof(line_t *) * height);
	for (uint32_t k=0; k<height; ++k) {
		l->data[k]   = malloc(sizeof(line_t) * width);
		l->buffer[k] = malloc(sizeof(line_t) * width);
	}
}

void led_free(struct led **pl)
{
	struct led *l = *pl;
	for (uint32_t k=0; k<l->height; ++k) {
		free(l->data[k]);
		free(l->buffer[k]);
	}
	free(l->data);
	free(l->buffer);
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

void clear(struct led *l)
{
	memset(l, 0, l->width*l->height*sizeof(line_t));
}

void push_if(int condition)
{
	if (condition) {
		// push 1
	} else {
		// push 0
	}
}

void update_display(struct led *l)
{
	for (uint32_t k=0; k<l->height; k++)
		memcpy(l->buffer[k], l->data[k], sizeof(line_t)*l->width);

	// while...
	for (uint32_t k=0; k<l->height; k++) {
		for (uint32_t n=0; n<l->height; n++)
			push_if(n == k);
		for (uint32_t j=0; j<l->width; j++) {
			line_t tmp = l->buffer[k][j];
			for (uint32_t n=0; n<l->length; n++) {
				push_if(tmp && 0b1);
				tmp <<= 1;
			}
		}
		// latch enable
	}
}

