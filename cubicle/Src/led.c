#include <string.h>
#include <stdbool.h>

#include "led.h"

bool in_range(int x, int y, int z)
{
	if (
			   x >= 0 && x < LENGTH
			&& y >= 0 && y < WIDTH
			&& z >= 0 && z < HEIGHT) {
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
void led_switch_on(struct led *l, int x, int y, int z)
{
	if (in_range(x,y,z))
		l->data[z][y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void led_switch_off(struct led *l, int x, int y, int z)
{
	if (in_range(x, y, z))
		if (l->data[z][y] & (1 << x))
			l->data[z][y] ^= 1 << x;
}

int led_get(struct led *l, int x, int y, int z)
{
	return ((l->data[z][y] >> x) & 1);
}

void led_reset(struct led *l)
{
	memset(l, 0, WIDTH*HEIGHT*sizeof(uint16_t));
}

/*

void push_if(int condition)
{
	if (condition) {
		// push 1
	} else {
		// push 0
	}
}

void led_display(struct led *l)
{
	for (int k=0; k<HEIGHT; k++) {
		for (int l=0; k<HEIGHT; l++)
			push_if(l == k);
		for (int j=0; j<WIDTH; j++) {
			uint16_t tmp = l->data[k][j];
			for (int l=0; l<LENGTH; l++) {
				push_if(tmp && 0b1);
				tmp <<= 1;
			}
		}
	}
}

*/
