#include "applications/crystal_structure/CUB_LED_list.h"
#include <stddef.h>
#include "constant.h"

void CUB_LED_list_init(CUB_LED_list_t *list)
{
	list->first = NULL;
	list->last  = NULL;
}

void CUB_LED_list_add(CUB_LED_list_t *list, CUB_LED_t *LED)
{
	CUB_LED_t *l = (CUB_LED_t *)MALLOC(sizeof(CUB_LED_t));
	l->x = LED->x;
	l->y = LED->y;
	l->z = LED->z;
	l->next = NULL;
	if (list->first == NULL) {
		list->first = l;
		list->last  = l;
	} else {
		list->last->next = l;
		list->last = l;
	}
}

void CUB_LED_list_free(CUB_LED_list_t *list)
{
	CUB_LED_t *cur_led = list->first;
	CUB_LED_t *next_led;
	while (cur_led != NULL) {
		next_led = cur_led->next;
		FREE(cur_led);
		cur_led = next_led;
	}
}

