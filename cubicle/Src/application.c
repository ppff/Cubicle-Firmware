
#include "CUB.h"
// for test led
#include "stm32f4xx_hal_conf.h"

void CUB_ApplicationRun()
{
	CUB_TextHome();
	CUB_TextPrint("Hello World :)");

	CUB_Event event;
	int count = 0;
	int loop = 0;
	/* Infinite loop */
	for(;;) {

		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 1);
						break;
					default:
						;
				}
			} else if (event.type == CUB_BUTTON_RELEASED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 0);
						count++;
						break;
					default:
						;
				}
			}
		}

		CUB_LEDs_switch_on(loop, 0,    0);
		CUB_LEDs_switch_on(0,    loop, 0);
		CUB_LEDs_switch_on(0,    0,    loop);
		CUB_LEDs_update_display();

		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
		CUB_Sleep(200);

		loop++;
	}
}
