#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <constant.h>

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
 * LEDs description:
 * %%%%%%% line     %%%%%%% line         %%%%%%% line 0   not in data,
 *         size_y-1         size_y-2                      only in buffer
 * 0000000111111111 0000000110100101 ... 0000000101010101 0000000000000001 <= plane 0
 * 0000000100000001 0000000110101101 ... 0000000111011010 0000000000000010 <= plane 1
 *                ^
 *              x = 0
 *              y = size_y-1
 *              z = 1
 * ...
 * %: unused bits.
 *
 * The content of the "data" field will be copied in "buffer" when updating
 * display,
 */
typedef struct CUB_LEDs {
	line_t **data;
	line_t **buffer;
	line_t **tmp;
	line_t *pointer_to_data;
	line_t *pointer_to_buffer;
} CUB_LEDs;

/**
 * Initialize a LED structure.
 */
void CUB_LEDs_init(CUB_LEDs *l);

/**
 * Free a LED structure.
 */
void CUB_LEDs_free(CUB_LEDs *l);

/**
 * Switch on the LED (x,y,z).
 */
void CUB_LEDs_switch_on(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z);

/**
 * Switch off the LED (x,y,z).
 */
void CUB_LEDs_switch_off(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z);

/**
 * Translate display (fill with 0).
 */
void CUB_LEDs_translate(CUB_LEDs *l, int32_t x, int32_t y, int32_t z);

/**
 * Switch off all LEDs.
 */
void CUB_LEDs_clear(CUB_LEDs *l);

/**
 * Display the LED structure on the cube.
 */
void CUB_LEDs_update_display(CUB_LEDs *l);

/**
 * Return 1 if LED (x,y,z) is on, else 0.
 */
int CUB_LEDs_get(CUB_LEDs *l, uint32_t x, uint32_t y, uint32_t z);

#ifdef STANDARD_COMPILATION
void CUB_LEDs_print(CUB_LEDs *l);
#endif

#endif
