#ifndef LED_H
#define LED_H

#include <stdint.h>


/**
 * Initialize a LED structure.
 */
void CUB_LEDs_init();

/**
 * Free a LED structure.
 */
void CUB_LEDs_free();

/**
 * Switch on the LED (x,y,z).
 */
void CUB_LEDs_switch_on(uint32_t x, uint32_t y, uint32_t z);

/**
 * Switch off the LED (x,y,z).
 */
void CUB_LEDs_switch_off(uint32_t x, uint32_t y, uint32_t z);

/**
 * Translate display (fill with 0).
 */
void CUB_LEDs_translate(int32_t x, int32_t y, int32_t z);

/**
 * Switch off all LEDs.
 */
void CUB_LEDs_clear();

/**
 * Display a LED structure on the cube.
 */
//void CUB_LEDs_display();

/**
 * Update the LED structure on the cube.
 */
void CUB_LEDs_update_display();

/**
 * Return 1 if LED (x,y,z) is on, else 0.
 */
int CUB_LEDs_get(uint32_t x, uint32_t y, uint32_t z);

#ifdef STANDARD_COMPILATION
void CUB_LEDs_print();
#endif

#endif
