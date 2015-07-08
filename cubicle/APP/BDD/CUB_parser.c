#include "CUB_parser.h"
#include <stddef.h>
#include <stdlib.h>

int CUB_parser_parse_file(void *get_next_line_arg, void *list_add_arg)
{
	char buff[64];

	/* Version */
	CUB_parser_get_next_line(buff, get_next_line_arg);
	uint32_t version = strtol(buff, NULL, 10);
	if (version > MAX_SUPPORTED_VERSION)
		return 1;

	/* Vectors */
	while (CUB_parser_get_next_line(buff, get_next_line_arg)) {
		char *p1 = buff;
		char *p2 = NULL;
		uint32_t x = strtol(p1, &p2, 10);
		uint32_t y = strtol(p2, &p1, 10);
		uint32_t z = strtol(p1, &p2, 10);
		CUB_parser_list_add(list_add_arg, x, y, z);
	}

	return 0;
}
