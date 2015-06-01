
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
	bool up_state = false;
	/* Infinite loop */
	for(;;) {

		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("UP pressed");
						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 1);
						up_state = true;
						break;
					case CUB_BTN_DOWN:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("DOWN pressed");
						break;
					case CUB_BTN_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("LEFT pressed");
						break;
					case CUB_BTN_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("RIGHT pressed");
						break;
					case CUB_BTN_TOP:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("TOP pressed");
						break;
					case CUB_BTN_BOTTOM:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("BOTTOM pressed");
						break;
					case CUB_BTN_M_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("M_LEFT pressed");
						break;
					case CUB_BTN_M_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("M_RIGHT pressed");
						break;
					case CUB_BTN_SM_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("SM_LEFT pressed");
						break;
					case CUB_BTN_SM_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("SM_RIGHT pressed");
						break;
					default:
						;
				}
			} else if (event.type == CUB_BUTTON_RELEASED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("UP released");
						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, 0);
						count++;
						up_state = false;
						break;
					case CUB_BTN_DOWN:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("DOWN released");
						break;
					case CUB_BTN_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("LEFT released");
						break;
					case CUB_BTN_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("RIGHT released");
						break;
					case CUB_BTN_TOP:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("TOP released");
						break;
					case CUB_BTN_BOTTOM:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("BOTTOM released");
						break;
					case CUB_BTN_M_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("M_LEFT released");
						break;
					case CUB_BTN_M_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("M_RIGHT released");
						break;
					case CUB_BTN_SM_LEFT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("SM_LEFT released");
						break;
					case CUB_BTN_SM_RIGHT:
						CUB_TextHome();
						CUB_TextClear();
						CUB_TextPrint("SM_RIGHT released");
						break;
					default:
						;
				}
			}
		}

		CUB_LEDs_switch_on(loop, 0,    0);
		CUB_LEDs_switch_on(0,    loop, 0);
		CUB_LEDs_switch_on(0,    0,    loop);
		CUB_LEDs_switch_on(loop,    loop,    loop);
		CUB_LEDs_update_display();

		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
		CUB_Sleep(1500);

		loop++;
	}
}

