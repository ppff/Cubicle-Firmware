#include "mem_management.h"
#include "FreeRTOS.h"
#include "string.h"
#include "stddef.h"
#include "constant.h"

void* realloc(void* pointer, size_t size)
{
	void* new_mem = malloc(size);
	new_mem = memcpy(new_mem, pointer, size);
	free(pointer);
	return new_mem;
}
