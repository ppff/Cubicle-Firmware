// gcc -c -o MyObj/CUB_Display.o Src/CUB_Display.c -std=gnu99 -Wall -IInc -DSTANDARD_COMPILATION
// gcc -o led_test Src/led_test.c -std=gnu99 -Wall -IInc MyObj/CUB_Display.o -DSTANDARD_COMPILATION

#include <assert.h>
#include <stdio.h>
#include "LEDs/CUB_LEDs.h"

int main(void)
{
	CUB_LEDs_init();
	CUB_LEDs_switch_on(0, 0, 0);
	CUB_LEDs_switch_on(1, 0, 0);
	CUB_LEDs_switch_on(2, 1, 0);
	CUB_LEDs_print();
	printf("Translate x +1:\n");
	CUB_LEDs_translate(1, 0, 0);
	CUB_LEDs_print();
	printf("Translate x -1:\n");
	CUB_LEDs_translate(-1, 0, 0);
	CUB_LEDs_print();
	printf("Translate y +1:\n");
	CUB_LEDs_translate(0, 1, 0);
	CUB_LEDs_print();
	printf("Translate y -1:\n");
	CUB_LEDs_translate(0, -1, 0);
	CUB_LEDs_print();
	printf("Translate z +1:\n");
	CUB_LEDs_translate(0, 0, 1);
	CUB_LEDs_print();
	printf("Translate z -1:\n");
	CUB_LEDs_translate(0, 0, -1);
	CUB_LEDs_print();

	CUB_LEDs_clear();
	for (int i=0; i<9; ++i)
		CUB_LEDs_switch_on(i, 0, 0);
	printf("Avant translation\n");
	CUB_LEDs_print();
	CUB_LEDs_translate(+1, 0, 0);
	CUB_LEDs_translate(-1, 0, 0);
	printf("Après translation\n");
	CUB_LEDs_print();
	CUB_LEDs_free();

	return 0;
}
