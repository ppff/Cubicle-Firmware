#ifndef LED_H
#define LED_H

#include <stdint.h>

/**
 * Type used to store the content of a line. It must verify:
 * sizeof(line_t) >= LENGTH
 */
typedef uint16_t line_t;

/**
 * Structure representing the LEDs of the cube.
 *
 * The structure must be initialized and freed.
 *
 * LED description:
 * %%%%%%% line 0   %%%%%%% line 1
 * 0000000111111111 0000000110100101 ... <= plane 0
 * 0000000100000001 0000000110101101 ... <= plane 1
 *                ^
 *    LED 0 of line 0 of plane 1
 * ...
 * %: unused bits.
 *
 * The content of the "data" field will be copied in "buffer" when updating
 * display,
 */
struct led {
	line_t **data;
	line_t **buffer;
	uint32_t length;
	uint32_t width;
	uint32_t height;
};

/**
 * Initialize a LED structure.
 */
void led_init(struct led *l, uint32_t length, uint32_t width, uint32_t height);

/**
 * Free a LED structure.
 */
void led_free(struct led **pl);

/**
 * Switch on the LED (x,y,z).
 */
void led_switch_on(struct led *l, uint32_t x, uint32_t y, uint32_t z);

/**
 * Switch off the LED (x,y,z).
 */
void led_switch_off(struct led *l, uint32_t x, uint32_t y, uint32_t z);

void CUB_translate(struct led *l, int32_t x, int32_t y, int32_t z);

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
int led_get(struct led *l, uint32_t x, uint32_t y, uint32_t z);

#endif
