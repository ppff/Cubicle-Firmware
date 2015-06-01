#include <stdint.h>

typedef struct CUB_LED {
	uint32_t x;
	uint32_t y;
	uint32_t z;
	struct CUB_LED *next;
} CUB_LED_t;

typedef struct CUB_LED_list {
	CUB_LED_t *first;
	CUB_LED_t *last;
} CUB_LED_list_t;

void CUB_LED_list_init(CUB_LED_list_t *list);

void CUB_LED_list_add(CUB_LED_list_t *list, CUB_LED_t *LED);

void CUB_LED_list_free(CUB_LED_list_t *list);

