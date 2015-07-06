#ifndef CUB_LED_LIST_H
#define CUB_LED_LIST_H

#include <stdint.h>

typedef struct CUB_LED {
	int32_t x;
	int32_t y;
	int32_t z;
	struct CUB_LED *next;
} CUB_LED_t;

typedef struct CUB_LED_list {
	CUB_LED_t *first;
	CUB_LED_t *last;
} CUB_LED_list_t;

void CUB_LED_list_init(CUB_LED_list_t *list);

void CUB_LED_list_add(CUB_LED_list_t *list, CUB_LED_t *LED);

void CUB_LED_list_free(CUB_LED_list_t *list);

#endif
