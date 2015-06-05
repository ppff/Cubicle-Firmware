#include "applications/api_rt/api_rt.h"

void apiRealTimeRun()
{
	//CUB_EnableButtonRepeat(700, 80);

	CUB_LEDs_clear();
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("API ready");
	CUB_ApiCommand cmd;
	CUB_Event event;
	/* Infinite loop */
	for(;;) {

		while (CUB_ApiGetNextCommand(&cmd)) {
			switch (cmd) {
			case CUB_API_RESET:
				break;
			case CUB_API_CLOSE:
				break;
			case CUB_API_GET_VERSION:
				CUB_ApiSend2("v", CUBICLE_VERSION_TXT);
				break;
			case CUB_API_CLEAR_LEDS:
				break;
			case CUB_API_LED_ON:
				break;
			case CUB_API_LED_OFF:
				break;
			case CUB_API_UP_LED_DISPLAY:
				break;
			case CUB_API_CLEAR_LCD:
				break;
			case CUB_API_SET_CURSOR:
				break;
			case CUB_API_PRINT:
				break;
			case CUB_API_ENABLE_BTN_REPEAT:
				break;
			case CUB_API_PUSH_EVENT:
				break;
			default:
				;
			}
		}

		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
				case CUB_BTN_UP:
					break;
				case CUB_BTN_DOWN:
					break;
				case CUB_BTN_TOP:
					break;
				case CUB_BTN_BOTTOM:
					break;
				case CUB_BTN_LEFT:
					break;
				case CUB_BTN_RIGHT:
					break;
				case CUB_BTN_M_LEFT:
					break;
				case CUB_BTN_M_RIGHT:
					break;
				case CUB_BTN_SM_LEFT:
					break;
				case CUB_BTN_SM_RIGHT:
					break;
				default:
					;
				}
			} else if (event.type == CUB_BUTTON_RELEASED) {
				switch (event.button.id) {
				case CUB_BTN_UP:
					break;
				case CUB_BTN_DOWN:
					break;
				case CUB_BTN_TOP:
					break;
				case CUB_BTN_BOTTOM:
					break;
				case CUB_BTN_LEFT:
					break;
				case CUB_BTN_RIGHT:
					break;
				case CUB_BTN_M_LEFT:
					break;
				case CUB_BTN_M_RIGHT:
					break;
				case CUB_BTN_SM_LEFT:
					break;
				case CUB_BTN_SM_RIGHT:
					break;
				default:
					;
				}
			}
		}

		CUB_Sleep(50);
	}
}

