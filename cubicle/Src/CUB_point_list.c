#include "CUB_point_list.h"

void point_list_free(point_list_t *l)
{
	point_list_element_t *e = l->first;
	point_list_element_t *next;
	while (e != NULL) {
		next = e->next;
		FREE(e);
		e = next;
	}
}

void point_list_add_element(point_list_t *l, point_t *p)
{
	point_list_element_t *previous_last = l->last;
	l->last = previous_last->next;
	l->last = (point_list_element_t *)MALLOC(sizeof(point_list_element_t));
	l->last->prev = previous_last;
	l->last->next = NULL;
	point_copy(&(l->last->p), p);
}

bool point_list_is_in(point_list_t *l, point_t *p)
{
	point_list_element_t *cur = l->first;
	while (cur != NULL) {
		if (point_equals(&(cur->p), p))
			return true;
		cur = cur->next;
	}
	return false;
}

