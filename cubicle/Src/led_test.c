#include <assert.h>
#include "CUB_Display.h"

int main(void)
{
	struct led l;
	led_init(&l, 9, 8, 10);
	led_switch_on(&l, 0, 0, 0);
	led_project(&l, 0, 0);
	led_project(&l, 1, 0);
	led_project(&l, 2, 0);
	led_free(&l);

	return 0;
}
