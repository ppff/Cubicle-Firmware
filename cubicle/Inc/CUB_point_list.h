#ifndef CUB_POINT_LIST_H
#define CUB_POINT_LIST_H

#include "CUB_point.h"

typedef struct point_list_element {
	point_t p;
	struct point_list_element *next;
	struct point_list_element *prev;
} point_list_element_t;

typedef struct point_list {
	point_list_element_t *first;
	point_list_element_t *last;
} point_list_t;

void point_list_free(point_list_t *l);

void point_list_add_element(point_list_t *l, point_t *p);

bool point_list_is_in(point_list_t *l, point_t *p);

void point_list_queue_to_head(point_list_t *l);

#endif
