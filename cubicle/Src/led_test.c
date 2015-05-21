#include <assert.h>
#include "led.h"

int main(void)
{
	struct led l;
	led_switch_on(&l, 1, 2, 3);
	assert(led_get(&l, 1, 2, 3) != 0);

	led_reset(&l);
	led_switch_on(&l, 1, 2, 3);
	led_switch_on(&l, 1, 2, 3);
	assert(led_get(&l, 1, 2, 3) != 0);

	led_reset(&l);
	led_switch_on(&l, 1, 2, 3);
	led_switch_off(&l, 1, 2, 3);
	led_switch_off(&l, 2, 3, 4);
	assert(led_get(&l, 1, 2, 3) == 0);
	assert(led_get(&l, 2, 3, 4) == 0);

	return 0;
}
