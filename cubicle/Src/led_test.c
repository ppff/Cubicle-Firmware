// gcc -c -o MyObj/CUB_Display.o Src/CUB_Display.c -std=gnu99 -Wall -IInc -DSTANDARD_COMPILATION
// gcc -o led_test Src/led_test.c -std=gnu99 -Wall -IInc MyObj/CUB_Display.o -DSTANDARD_COMPILATION

#include <assert.h>
#include <stdio.h>
#include "CUB_Display.h"

int main(void)
{
	struct led l;
	led_init(&l, 9, 8, 10);
	led_switch_on(&l, 0, 0, 0);
	led_switch_on(&l, 1, 0, 0);
	led_switch_on(&l, 2, 1, 0);
	led_print(&l);
	printf("Translate x +1:\n");
	CUB_translate(&l, 1, 0, 0);
	led_print(&l);
	printf("Translate x -1:\n");
	CUB_translate(&l, -1, 0, 0);
	led_print(&l);
	printf("Translate y +1:\n");
	CUB_translate(&l, 0, 1, 0);
	led_print(&l);
	printf("Translate y -1:\n");
	CUB_translate(&l, 0, -1, 0);
	led_print(&l);
	printf("Translate z +1:\n");
	CUB_translate(&l, 0, 0, 1);
	led_print(&l);
	printf("Translate z -1:\n");
	CUB_translate(&l, 0, 0, -1);
	led_print(&l);
	led_free(&l);

	return 0;
}
