#include "applications/crystal_structure/CUB_parser.h"
#include <stdlib.h>
#include <stdio.h>
#define CUBICLE_FIRMWARE
#define MAX_SUPPORTED_VERSION 1

#ifdef CUBICLE_FIRMWARE
int CUB_parse_file(char *filename, CUB_LED_list_t *l)
#endif
{
	FILE *file = fopen(filename, "r");
#ifdef CUBICLE_FIRMWARE
	CUB_LED_list_init(l);
#endif

	/* Version */
	char *p1 = /* get_line() */ NULL;
	uint32_t version = strtol(p1, NULL, 10);
	if (version > MAX_SUPPORTED_VERSION)
		return 1;

	/* Vectors */
	while ((p1 /* = get_line */) != NULL) {
		char *p2 = NULL;
		uint32_t x = strtol(p1, &p2, 10);
		uint32_t y = strtol(p2, &p1, 10);
		uint32_t z = strtol(p1, &p2, 10);
#ifdef CUBICLE_FIRMWARE
		CUB_LED_t led = {x, y, z, NULL};
		CUB_LED_list_add(l, &led);
#endif
	}
	fclose(file);
	return 0;
}

