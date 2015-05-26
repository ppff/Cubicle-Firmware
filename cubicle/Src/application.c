
#include "CUB.h"
// for test led
#include "stm32f4xx_hal_conf.h"

void CUB_ApplicationRun()
{
	CUB_TextHome();
	CUB_TextPrint("Hello World :)");

	CUB_Event event;
	/* Infinite loop */
	for(;;) {

		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_DOWN) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
						break;
					default:
						;
				}
			}
		}


		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
		CUB_Sleep(200);
	}
}

