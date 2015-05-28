#ifndef CUB_POINT_H
#define CUB_POINT_H

#include <stdint.h>
#include <stdbool.h>

typedef struct point {
	uint32_t x;
	uint32_t y;
	uint32_t z;
} point_t;

bool point_equals(point_t *p1, point_t *p2);

void point_copy(point_t *p1, point_t *p2);

#endif
