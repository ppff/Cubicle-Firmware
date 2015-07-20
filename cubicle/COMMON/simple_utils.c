#include "simple_utils.h"
#include "stdint.h"


/**
 * REALLY DUMB IMPLEMENTATION! CHECK WHAT YOU PASS TO THIS THING!
 */
uint8_t atoi(char* p)
{
	uint8_t k = 0;
	while(*p)
	{
		k = k*10+*(p)-'0';
		p++;
	}
	return k;
}
