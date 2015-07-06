#include "CUB_point.h"

bool point_equals(point_t *p1, point_t *p2)
{
	if (
			   p1->x == p2->x
			&& p1->y == p2->y
			&& p1->z == p2->z)
		return true;
	return false;
}

void point_copy(point_t *p1, point_t *p2)
{
	p1->x = p2->x;
	p1->y = p2->y;
	p1->z = p2->z;
}
