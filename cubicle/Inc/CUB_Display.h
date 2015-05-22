#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "constant.h"

/**
 * Type used to store the content of a line. It must verify:
 * sizeof(line_t) >= LENGTH
 */
typedef uint16_t line_t;

/**
 * Structure representing the LEDs of the cube.
 *
 * 0000000111111111 0000000110100101 ... <= plane 0
 * %%%%%%% line 0   %%%%%%% line 1
 * 0000000100000001 0000000110101101 ... <= plane 1
 *                ^
 *    LED 0 of line 0 of plane 1
 * ...
 *
 * %: unused bits.
 */
struct led {
	line_t data[HEIGHT][WIDTH];
};

/**
 * Switch on the LED (x,y,z).
 */
void led_switch_on(struct led *l, int x, int y, int z);

/**
 * Switch off the LED (x,y,z).
 */
void led_switch_off(struct led *l, int x, int y, int z);

/**
 * Switch off all LEDs.
 */
void clear(struct led *l);

/**
 * Display the LED structure on the cube.
 */
void update_display(struct led *l);

/**
 * Return 1 if LED (x,y,z) is on, else 0.
 */
int led_get(struct led *l, int x, int y, int z);

#endif
