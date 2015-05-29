#include "CUB.h"
#include "LEDs/CUB_LEDs.h"
#include "string.h"
#include "stdio.h"

#define SCREEN_WIDTH 32

uint32_t ng;

typedef struct group {
	char *name;
	uint32_t index;
	uint32_t nb_pattern;
} group_t;

typedef struct pattern {
	char *name;
	uint32_t index;
} pattern_t;

uint32_t get_nb_group();

group_t *get_next_group();
group_t *get_prev_group();

pattern_t *get_next_pattern();
pattern_t *get_prev_pattern();

void update_screen_display(group_t *g, pattern_t *p)
{
	char group_number_display[6 + 1]; // XX/XX  //
	char group_name_display[SCREEN_WIDTH - 6 +1];
	char pattern_number_display[6 + 1];
	char pattern_name_display[SCREEN_WIDTH - 6 +1];
	char screen[SCREEN_WIDTH * 2 + 1];

	sprintf(group_number_display, "%u/%u ", g->index, ng);
	strncpy(group_name_display, g->name, 6);
	group_name_display[SCREEN_WIDTH - 6] = '\0';

	sprintf(group_number_display, "%u/%u ", p->index, g->nb_pattern);
	strncpy(pattern_name_display, p->name, 6);
	pattern_name_display[SCREEN_WIDTH - 6] = '\0';

	sprintf(screen, "%s%s\n%s%s",
			group_number_display,
			group_name_display,
			pattern_number_display,
			pattern_name_display);
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint(screen);
}

void CUB_ApplicationRun()
{
	group_t   *g = get_next_group();
	pattern_t *p = get_next_pattern();
	update_screen_display(g, p);

	CUB_Event event;
	int count = 0;
	int loop = 0;
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
			}
			// Cech if SD card is still in slot.
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
