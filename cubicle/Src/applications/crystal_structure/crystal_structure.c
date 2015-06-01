#include <string.h>
#include <stdio.h>

#include "CUB.h"
#include "LEDs/CUB_LEDs.h"
#define CUBICLE_FIRMWARE
#include "applications/crystal_structure/CUB_parser.h"
#include "applications/crystal_structure/CUB_LED_list.h"

#define SCREEN_WIDTH 32

typedef struct group {
	char *name;
	uint32_t index;
	uint32_t nb_pattern;
} group_t;

typedef struct pattern {
	char *name;
	uint32_t index;
	char *path;
} pattern_t;

typedef enum action {
	NEXT_GROUP = 0,
	PREV_GROUP,
	NEXT_PATTERN,
	PREV_PATTERN,
} action_t;

group_t   cur_group;
pattern_t cur_pattern;
uint32_t  nb_group;

void group_and_pattern_init();
void group_and_pattern_update(action_t action);

void screen_display_update()
{
	char group_number_display  [6 + 1]; // XX/XX  //
	char group_name_display    [SCREEN_WIDTH - 6 +1];
	char pattern_number_display[6 + 1];
	char pattern_name_display  [SCREEN_WIDTH - 6 +1];
	char screen                [SCREEN_WIDTH * 2 + 1];

	sprintf(group_number_display, "%u/%u ", cur_group.index, nb_group);
	strncpy(group_name_display, cur_group.name, 6);
	group_name_display[SCREEN_WIDTH - 6] = '\0';

	sprintf(group_number_display, "%u/%u ", cur_pattern.index, cur_group.nb_pattern);
	strncpy(pattern_name_display, cur_pattern.name, 6);
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

void pattern_display_update()
{
	CUB_LED_list_t list;
	CUB_LED_list_init(&list);
	int status = CUB_parse_file(cur_pattern.path, &list);
	if (status == 1) {
		/* Do something */
	}
	CUB_LEDs_clear();
	CUB_LED_t *cur_led = list.first;
	while (cur_led != NULL) {
		CUB_LEDs_switch_on(cur_led->x, cur_led->y, cur_led->z);
		cur_led = cur_led->next;
	}
	CUB_LEDs_update_display();
}

void application_init()
{
	group_and_pattern_init();
	screen_display_update();
	pattern_display_update();
}

void application_update(action_t action)
{
	group_and_pattern_update(action);
	screen_display_update();
	pattern_display_update();
}

void CUB_ApplicationRun()
{
	application_init();

	CUB_Event event;
	int count = 0;
	int loop = 0;
	/* Infinite loop */
	for(;;) {
		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						break;
					case CUB_BTN_DOWN:
						break;
					case CUB_BTN_LEFT:
						break;
					case CUB_BTN_RIGHT:
						break;
					case CUB_BTN_TOP:
						break;
					case CUB_BTN_BOTTOM:
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

		CUB_LEDs_switch_on(loop, 0,    0);
		CUB_LEDs_switch_on(0,    loop, 0);
		CUB_LEDs_switch_on(0,    0,    loop);
		CUB_LEDs_update_display();

		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
		CUB_Sleep(200);

		loop++;
	}
}
