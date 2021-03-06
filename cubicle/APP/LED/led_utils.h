#ifndef _LED_UTILS_H_
#define _LED_UTILS_H_

#include "stdbool.h"

/**
 * Set LED on
 */
void led_set(uint8_t x, uint8_t y, uint8_t z);

/**
 * Set LED off
 */
void led_unset(uint8_t x, uint8_t y, uint8_t z);

/**
 * Toggle LED state
 */
void led_toggle(uint8_t x, uint8_t y, uint8_t z);

/**
 * Change LED to the given state
 */
void led_set_state(uint8_t x, uint8_t y, uint8_t z, bool state);

/**
 * Check LED state
 */
bool led_get(uint8_t x, uint8_t y, uint8_t z);

/**
 * Send data to sink drivers
 */
bool led_update();

#endif
