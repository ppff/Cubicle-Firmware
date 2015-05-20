#ifndef LED_H
#define LED_H

/**
 * Structure representing the LEDs of the cube.
 */
struct led;

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
void led_reset(struct led *l);

/**
 * Display the LED structure on the cube.
 */
void led_display(struct led *l);

#endif
