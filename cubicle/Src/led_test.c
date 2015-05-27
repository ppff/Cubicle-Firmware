// gcc -c -o MyObj/CUB_Display.o Src/CUB_Display.c -std=gnu99 -Wall -IInc -DSTANDARD_COMPILATION
// gcc -o led_test Src/led_test.c -std=gnu99 -Wall -IInc MyObj/CUB_Display.o -DSTANDARD_COMPILATION

#include <assert.h>
#include <stdio.h>
#include "LEDs/CUB_LEDs.h"

int main(void)
{
	CUB_LEDs l;
	CUB_LEDs_init(&l, 9, 8, 10);
	CUB_LEDs_switch_on(&l, 0, 0, 0);
	CUB_LEDs_switch_on(&l, 1, 0, 0);
	CUB_LEDs_switch_on(&l, 2, 1, 0);
	CUB_LEDs_print(&l);
	printf("Translate x +1:\n");
	CUB_LEDs_translate(&l, 1, 0, 0);
	CUB_LEDs_print(&l);
	printf("Translate x -1:\n");
	CUB_LEDs_translate(&l, -1, 0, 0);
	CUB_LEDs_print(&l);
	printf("Translate y +1:\n");
	CUB_LEDs_translate(&l, 0, 1, 0);
	CUB_LEDs_print(&l);
	printf("Translate y -1:\n");
	CUB_LEDs_translate(&l, 0, -1, 0);
	CUB_LEDs_print(&l);
	printf("Translate z +1:\n");
	CUB_LEDs_translate(&l, 0, 0, 1);
	CUB_LEDs_print(&l);
	printf("Translate z -1:\n");
	CUB_LEDs_translate(&l, 0, 0, -1);
	CUB_LEDs_print(&l);
	CUB_LEDs_free(&l);

	return 0;
}
