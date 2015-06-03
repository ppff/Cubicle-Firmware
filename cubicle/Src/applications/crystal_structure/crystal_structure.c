#include <string.h>
#include <stdio.h>

#include "CUB.h"
#include "LEDs/CUB_LEDs.h"
#include "CUB_parser.h"
#include "applications/crystal_structure/CUB_LED_list.h"
#include "applications/snake.h"

#define SCREEN_WIDTH 32

void inverse2(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void my_itoa2(int value, char str[]) 
{
	int i = 0;
	if (value >= 0) {
		do {
			str[i++] = value % 10 + '0';
		} while ((value /= 10) > 0);
		str[i] = '\0';
		inverse2(str);
	} else {
		strcpy(str,"");
	}
}


typedef struct pattern {
	char *name;
	uint32_t index;
#ifdef FAKEDEMO
	CUB_LED_list_t data;
#else
	char *path;
#endif
} pattern_t;


typedef struct group {
	char *name;
	uint32_t index;
	uint32_t nb_pattern;
	pattern_t *patterns;	
} group_t;

typedef enum action {
	NEXT_GROUP = 0,
	PREV_GROUP,
	NEXT_PATTERN,
	PREV_PATTERN,
} action_t;

group_t   cur_group;
pattern_t cur_pattern;
uint32_t  nb_group;
group_t *groups;
int status;

void group_and_pattern_init()
{
#ifdef FAKEDEMO
	nb_group = 3;
	groups = MALLOC(sizeof(group_t)*nb_group);

	groups[0].name, strdup("Daniel");
	groups[0].index = 0;
	groups[0].nb_pattern = 3;
	groups[0].patterns = MALLOC(sizeof(pattern_t)*3);
	groups[0].patterns[0].name = strdup("Premier motif");
	CUB_LED_list_init(&groups[0].patterns[0].data);
	CUB_LED_list_add(&groups[0].patterns[0].data, {0,0,0});
	CUB_LED_list_add(&groups[0].patterns[0].data, {2,2,2});

#endif
}

void group_and_pattern_update(action_t action)
{

}

void status_update(CUB_Button b)
{
	switch (status) {
	case 0:
		status = (b == CUB_BTN_UP) ? 1 : 0;
		break;
	case 1:
		status = (b == CUB_BTN_UP) ? 2 : 0;
		break;
	case 2:
		status = (b == CUB_BTN_DOWN) ? 3 : 0;
		break;
	case 3:
		status = (b == CUB_BTN_DOWN) ? 4 : 0;
		break;
	case 4:
		status = (b == CUB_BTN_LEFT) ? 5 : 0;
		break;
	case 5:
		status = (b == CUB_BTN_RIGHT) ? 6 : 0;
		break;
	case 6:
		status = (b == CUB_BTN_LEFT) ? 7 : 0;
		break;
	case 7:
		status = (b == CUB_BTN_RIGHT) ? 8 : 0;
		break;
	case 8:
		status = (b == CUB_BTN_M_LEFT) ? 9 : 0;
		break;
	case 9:
		status = (b == CUB_BTN_M_RIGHT) ? 10 : 0;
		break;
	default:
		status = 0;
		break;
	}
	CUB_TextClear();
	CUB_TextHome();
	char score_string[16];
	my_itoa2(status, score_string);
	CUB_TextPrint(score_string);
}

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

/*
void application_init()
{
	group_and_pattern_init();
	screen_display_update();
	pattern_display_update();
	status = 0;
}

void application_update(action_t action)
{
	group_and_pattern_update(action);
	screen_display_update();
	pattern_display_update();
}
*/

void CUB_ApplicationRun()
{
	//application_init();

	CUB_LEDs_clear();
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("toto");
	CUB_Event event;
	int count = 0;
	int loop = 0;
	/* Infinite loop */
	for(;;) {
		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				status_update(event.button.id);
				if (status == 10) {
<<<<<<< Updated upstream
					CUB_ApplicationRun_snake();
					status = 0;
=======
					// TODO
					CUB_TextHome();
					CUB_TextPrint("OK");
>>>>>>> Stashed changes
				}
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
						//application_update(PREV_GROUP);
						break;
					case CUB_BTN_M_RIGHT:
						//application_update(NEXT_GROUP);
						break;
					case CUB_BTN_SM_LEFT:
						//application_update(PREV_PATTERN);
						break;
					case CUB_BTN_SM_RIGHT:
						//application_update(NEXT_PATTERN);
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
