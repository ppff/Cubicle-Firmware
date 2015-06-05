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
				//CUB_ApiReset();
				break;
			case CUB_API_CLOSE:
				// return to caller application
				return;
				break;
			case CUB_API_GET_VERSION:
				CUB_ApiSend2("v", CUBICLE_VERSION_TXT);
				break;
	
			case CUB_API_CLEAR_LEDS:
				CUB_LEDs_clear();
				break;
			case CUB_API_LED_ON: {
				uint32_t x, y, z;
				x = CUB_ApiGetNextUint32();
				y = CUB_ApiGetNextUint32();
				z = CUB_ApiGetNextUint32();
				CUB_LEDs_switch_on(x, y, z);
				} break;
			case CUB_API_LED_OFF: {
				uint32_t x, y, z;
				x = CUB_ApiGetNextUint32();
				y = CUB_ApiGetNextUint32();
				z = CUB_ApiGetNextUint32();
				CUB_LEDs_switch_off(x, y, z);
				} break;
			case CUB_API_UPDATE_LED_DISPLAY:
				CUB_LEDs_update_display();
				break;
			case CUB_API_IMM_CLEAR_LEDS:
				CUB_LEDs_clear();
				CUB_LEDs_update_display();
				break;
			case CUB_API_IMM_LED_ON: {
				uint32_t x, y, z;
				x = CUB_ApiGetNextUint32();
				y = CUB_ApiGetNextUint32();
				z = CUB_ApiGetNextUint32();
				CUB_LEDs_switch_on(x, y, z);
				CUB_LEDs_update_display();
				} break;
			case CUB_API_IMM_LED_OFF: {
				uint32_t x, y, z;
				x = CUB_ApiGetNextUint32();
				y = CUB_ApiGetNextUint32();
				z = CUB_ApiGetNextUint32();
				CUB_LEDs_switch_off(x, y, z);
				CUB_LEDs_update_display();
				} break;

			case CUB_API_CLEAR_LCD:
				CUB_TextClear();
				break;
			case CUB_API_SET_CURSOR:
				break;
			case CUB_API_PRINT: {
				uint8_t c;
				while ((c = CUB_ApiGetNextUint8())) {
//					CUB_TextPrintChar((char)c);
				}
				} break;

			case CUB_API_ENABLE_BTN_REPEAT: {
				uint16_t delay, interval;
				delay = CUB_ApiGetNextUint16();
				interval = CUB_ApiGetNextUint16();
				CUB_EnableButtonRepeat(delay, interval);
				} break;

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

		CUB_Sleep(10);
	}
}

