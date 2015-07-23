#include "led_utils.h"
#include "stdbool.h"

/**
 * buffer containing led data to be sent to sink drivers
 */
static uint16_t led_buffer[][] = {
	// 1th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000000001, // layer selection
	},
	// 2th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000000010, // layer selection
	},
	// 3th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000000100, // layer selection
	},
	// 4th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000001000, // layer selection
	},
	// 5th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000010000, // layer selection
	},
	// 6th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000000100000, // layer selection
	},
	// 7th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000001000000, // layer selection
	},
	// 8th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000010000000, // layer selection
	},
	// 9th layer
	{
		0b0000000000000000, // 1th row of columns
		0b0000000000000000, // 2th row of columns
		0b0000000000000000, // 3th row of columns
		0b0000000000000000, // 4th row of columns
		0b0000000000000000, // 5th row of columns
		0b0000000000000000, // 6th row of columns
		0b0000000000000000, // 7th row of columns
		0b0000000000000000, // 8th row of columns
		0b0000000000000000, // 9th row of columns
		0b0000000100000000, // layer selection
	}
}


void led_set(uint8_t x, uint8_t y, uint8_t z)
{
	led_buffer[z][y] |= ( 1 << x );
}

void led_unset(uint8_t x, uint8_t y, uint8_t z)
{
	led_buffer[z][y] &= ~( 1 << x );
}


void led_toggle(uint8_t x, uint8_t y, uint8_t z)
{
	led_buffer[z][y] ^= ( 1 << x );
}


void led_set_state(uint8_t x, uint8_t y, uint8_t z, bool state)
{
	led_buffer[z][y] ^= (-state ^ led_buffer[z][y]) & ( 1 << x );
}


bool led_get(uint8_t x, uint8_t y, uint8_t z)
{
	return (bool) ( (led_buffer[z][y] >> x) & 1 );
}


bool led_update()
{
	return 0;
}
