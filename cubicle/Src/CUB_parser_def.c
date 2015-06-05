#include "fatfs.h"
#include "CUB_parser_def.h"
#include "applications/crystal_structure/CUB_LED_list.h"

bool CUB_parser_get_next_line(char buff[64], void *arg)
{
	FIL *file = arg;
	return (f_gets(buff, 64, file) != NULL) ? true : false;
}

void CUB_parser_list_add(void *list, uint32_t x, uint32_t y, uint32_t z)
{
	CUB_LED_t led = {x, y, z, NULL};
	CUB_LED_list_add(list, &led);
}
