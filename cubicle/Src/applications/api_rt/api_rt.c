#include "applications/api_rt/api_rt.h"

void apiRealTimeRun()
{
	CUB_EnableButtonRepeat(700, 80);

	CUB_LEDs_clear();
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("toto");
	CUB_ApiCommand cmd;
	CUB_Event event;
	int loop = 0;
	/* Infinite loop */
	for(;;) {


//		while ((cmd = CUB_ApiGetNextCommand()) != CUB_API_NO_CMD) {
//			switch (cmd) {
//			case CUB_API_GET_VERSION:
//				CUB_ApiSend2("v", CUBICLE_VERSION_TXT);
//
//				break;
//
//			}
//
//
//		}
//		uint8_t cmd = CUB_ApiGetNextByte();

		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				if (status_update(event.button.id))
					CUB_ApplicationRun_snake();
				switch (event.button.id) {
					case CUB_BTN_UP:
						pattern_display_update(-1, 0, 0);
						break;
					case CUB_BTN_DOWN:
						pattern_display_update(1, 0, 0);
						break;
					case CUB_BTN_LEFT:
						pattern_display_update(0, -1, 0);
						break;
					case CUB_BTN_RIGHT:
						pattern_display_update(0, 1, 0);
						break;
					case CUB_BTN_TOP:
						pattern_display_update(0, 0, 1);
						break;
					case CUB_BTN_BOTTOM:
						pattern_display_update(0, 0, -1);
						break;
					case CUB_BTN_M_LEFT:
						application_update(PREV_GROUP);
						break;
					case CUB_BTN_M_RIGHT:
						application_update(NEXT_GROUP);
						break;
					case CUB_BTN_SM_LEFT:
						application_update(PREV_PATTERN);
						break;
					case CUB_BTN_SM_RIGHT:
						application_update(NEXT_PATTERN);
						break;
					default:
						;
				}
			}
			// Cech if SD card is still in slot.
		}

		CUB_Sleep(50);

		loop++;
	}
}
