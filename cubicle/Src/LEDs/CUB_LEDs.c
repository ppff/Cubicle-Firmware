#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "LEDs/CUB_LEDs.h"

#ifndef STANDARD_COMPILATION
#include "FreeRTOS.h"
#include "spi.h"
#include "cmsis_os.h"
#endif

#include "constant.h"

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

#ifndef STANDARD_COMPILATION
/*
 * Thread to always refresh real LED matrix
 */
static osThreadId refreshTaskHandle;
static void _refresh(void const * arg);
#endif
static CUB_LEDs mMainLEDs; // to use
static line_t translate_plus_x_mask = 0;

void CUB_LEDs_init()
{
	CUB_LEDs *l = &mMainLEDs;
	l->data   = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->buffer = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->tmp    = MALLOC(sizeof(line_t *) * SIZE_Z);
	l->pointer_to_data   = MALLOC(sizeof(line_t) * SIZE_Y     * SIZE_Z);
	l->pointer_to_buffer = MALLOC(sizeof(line_t) * (SIZE_Y+1) * SIZE_Z);
	for (uint32_t k=0; k<SIZE_X; ++k) {
		l->data[k]   = l->pointer_to_data   + SIZE_Y     * k;
		l->buffer[k] = l->pointer_to_buffer + (SIZE_Z+1) * k;
		l->buffer[k][SIZE_Y] = 1 << k;
	}
	for (uint32_t j=0; j<SIZE_Y; ++j) {
		translate_plus_x_mask <<= 1;
		translate_plus_x_mask |= 1;
	}

#ifndef STANDARD_COMPILATION
	// launch task to always refresh
	osThreadDef(REFRESH_TASK, _refresh, osPriorityNormal, 0, 128);
	refreshTaskHandle = osThreadCreate(osThread(REFRESH_TASK), NULL);
#endif
}

void CUB_LEDs_free()
{
	CUB_LEDs *l = &mMainLEDs;
	FREE(l->pointer_to_data);
	FREE(l->pointer_to_buffer);
}

bool CUB_LEDs_in_range(uint32_t x, uint32_t y, uint32_t z)
{
	return (x < SIZE_X && y < SIZE_Y && z < SIZE_Z);
}

/**
 * line: 0000010001
 * mask: 0000000100
 * or:   0000010101 <= LED on
 */
void CUB_LEDs_switch_on(uint32_t x, uint32_t y, uint32_t z)
{
	CUB_LEDs *l = &mMainLEDs;
	if (CUB_LEDs_in_range(x, y, z))
		l->data[z][SIZE_Y-1-y] |= 1 << x;
}

/**
 * line: 0000010101
 * mask: 0000000100
 * xor:  0000010001 <= LED off
 */
void CUB_LEDs_switch_off(uint32_t x, uint32_t y, uint32_t z)
{
	CUB_LEDs *l = &mMainLEDs;
	if (CUB_LEDs_in_range(x, y, z))
		if (l->data[z][SIZE_Y-1-y] & (1 << x))
			l->data[z][SIZE_Y-1-y] ^= 1 << x;
}

int CUB_LEDs_get(uint32_t x, uint32_t y, uint32_t z)
{
	CUB_LEDs *l = &mMainLEDs;
	if (CUB_LEDs_in_range(x, y, z)) {
		return ((l->data[z][SIZE_Y-1-y] >> x) & 1);
	} else {
		return 0;
	}
}

void CUB_LEDs_translate_x(int32_t x)
{
	CUB_LEDs *l = &mMainLEDs;
	if (x > 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k) {
			for (uint32_t j=0; j<SIZE_Y; ++j) {
				l->data[k][SIZE_Y-1-j] <<= x;
				l->data[k][SIZE_Y-1-j] &= translate_plus_x_mask;
			}
		}
	} else if (x < 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k)
			for (uint32_t j=0; j<SIZE_Y; ++j)
				l->data[k][SIZE_Y-1-j] >>= -x;
	}
}

void CUB_LEDs_translate_y(int32_t y)
{
	CUB_LEDs *l = &mMainLEDs;
	if (y > 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k) {
			for (uint32_t j=0; j<(uint32_t)(SIZE_Y-y); ++j)
				l->data[k][j] = l->data[k][j+y];
			for (uint32_t j=SIZE_Y-y; j<SIZE_Y; ++j)
				l->data[k][j] = 0;
		}
	} else if (y < 0) {
		for (uint32_t k=0; k<SIZE_Z; ++k) {
			for (uint32_t j=0; j<(uint32_t)(SIZE_Y+y); ++j)
				l->data[k][SIZE_Y-1-j] = l->data[k][SIZE_Y-1-j+y];
			for (uint32_t j=SIZE_Y+y; j<SIZE_Y; ++j)
				l->data[k][SIZE_Y-1-j] = 0;
		}
	}
}

void CUB_LEDs_translate_z(int32_t z)
{
	CUB_LEDs *l = &mMainLEDs;
	for (uint32_t k=0; k<SIZE_Z; ++k)
		l->tmp[k] = l->data[k];
	for (uint32_t k=0; k<SIZE_Z; ++k) {
		int32_t ind = k-z;
		if (ind >= (int32_t)SIZE_Z)
			ind -= SIZE_Z;
		if (ind < 0)
			ind += SIZE_Z;
		l->data[k] = l->tmp[ind];
	}
	if (z > 0) {
		for (uint32_t k=0; k<(uint32_t)z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*SIZE_Y);
	} else if (z < 0) {
		for (uint32_t k=SIZE_Z-z; k<SIZE_Z; ++k)
			memset(l->data[k], 0, sizeof(line_t)*SIZE_Y);
	}
}

void CUB_LEDs_translate(int32_t x, int32_t y, int32_t z)
{
	if (x != 0)
		CUB_LEDs_translate_x(x);
	if (y != 0)
		CUB_LEDs_translate_y(y);
	if (z != 0)
		CUB_LEDs_translate_z(z);
}

void CUB_LEDs_clear()
{
	CUB_LEDs *l = &mMainLEDs;
	for (uint32_t k=0; k<SIZE_Z; ++k)
		memset(l->data[k], 0, SIZE_Y*sizeof(line_t));
}

#ifndef STANDARD_COMPILATION
void CUB_LEDs_update_display()
{
	CUB_LEDs *l = &mMainLEDs;
	for (uint32_t k=0; k<SIZE_Z; k++)
		memcpy(l->buffer[k], l->data[k], sizeof(line_t)*SIZE_Y);
}

void CUB_LEDs_display()
{
	CUB_LEDs *l = &mMainLEDs;
	HAL_StatusTypeDef status;
	uint32_t k=0;
	for (;;) {
		do {
			status = HAL_SPI_Transmit(&hspi4, (uint8_t*)l->buffer[k], (SIZE_Y+1), 15);
		} while (status != HAL_OK);

		// latch enable
		for (int i=0; i < 40; i++) ; 
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
		for (int i=0; i < 40; i++) ; // 40 tours de boucles == 3 µs
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);

		k = (k+1) % (SIZE_Z);
		osDelay(10);
	}
}


static void _refresh(void const * arg)
{
	CUB_LEDs_display();
}
#endif

#ifdef STANDARD_COMPILATION
void CUB_LEDs_print()
{
	CUB_LEDs *l = &mMainLEDs;
	for (uint32_t k=0; k<SIZE_Z; ++k) {
		for (uint32_t j=0; j<SIZE_Y; ++j) {
			line_t tmp = l->data[k][SIZE_Y-1-j];
			for (uint32_t i=0; i<SIZE_X; ++i) {
				if (tmp >> i & 1)
					printf("(%u, %u, %u)\n", i, j, k);
			}
		}
	}
}
#endif

