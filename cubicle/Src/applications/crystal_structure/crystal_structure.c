#include <string.h>
#include <stdio.h>

#include "CUB.h"
#include "LEDs/CUB_LEDs.h"
#include "CUB_parser.h"
#include "applications/crystal_structure/CUB_LED_list.h"
#include "applications/snake.h"
#include "constant.h"

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
#ifdef FAKEDEMO
#else
	char *path;
#endif
	CUB_LED_list_t data;
} pattern_t;


typedef struct group {
	char *name;
	uint32_t nb_pattern;
	pattern_t *patterns;	
} group_t;

typedef enum action {
	NEXT_GROUP = 0,
	PREV_GROUP,
	NEXT_PATTERN,
	PREV_PATTERN,
} action_t;

uint32_t  nb_group;
group_t *groups;
uint32_t  cur_group_id;
uint32_t  cur_pattern_id;
int status = 0;
int32_t x_offset = 0;
int32_t y_offset = 0;
int32_t z_offset = 0;

char * mystrdup(const char *src)
{
	char * copy = MALLOC(strlen(src)+1);
	strcpy(copy, src);
	return copy;
}

void group_and_pattern_init()
{
#ifdef FAKEDEMO
	nb_group = 2;
	groups = MALLOC(sizeof(group_t)*nb_group);

	groups[0].name = mystrdup("Daniel");
	groups[1].name = mystrdup("Florian");
	groups[0].nb_pattern = 2;
	groups[1].nb_pattern = 1;
	groups[0].patterns = MALLOC(sizeof(pattern_t)*groups[0].nb_pattern);
	groups[1].patterns = MALLOC(sizeof(pattern_t)*groups[1].nb_pattern);
	groups[0].patterns[0].name = mystrdup("Premier motif");
	groups[1].patterns[0].name = mystrdup("Premier motif");
	CUB_LED_list_init(&groups[0].patterns[0].data);
	CUB_LED_list_init(&groups[1].patterns[0].data);
	CUB_LED_t led = {0,0,0,NULL};
	CUB_LED_list_add(&groups[0].patterns[0].data, &led);
	led.z++;
	CUB_LED_list_add(&groups[0].patterns[0].data, &led);
	groups[0].patterns[1].name = mystrdup("Deuxieme motif");
	CUB_LED_list_init(&groups[0].patterns[1].data);
	led.z++;
	CUB_LED_list_add(&groups[0].patterns[1].data, &led);
	led.z++;
	CUB_LED_list_add(&groups[0].patterns[1].data, &led);

	led.x = 0;
	led.y = 0;
	led.z = 0;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 2;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.y = 2;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.z = 2;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.y = 0;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 0;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 0;
	led.y = 2;
	led.z = 0;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 2;
	led.y = 0;
	led.z = 2;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 0;
	led.y = 2;
	led.z = 2;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	led.x = 1;
	led.y = 1;
	led.z = 1;
	CUB_LED_list_add(&groups[1].patterns[0].data, &led);
	cur_group_id = cur_pattern_id = 0;
#endif
	x_offset = 0;
	y_offset = 0;
	z_offset = 0;
}

void group_and_pattern_update(action_t action)
{
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("tata");
	switch (action) {
	case NEXT_PATTERN:
		cur_pattern_id = (cur_pattern_id != groups[cur_group_id].nb_pattern - 1) ? cur_pattern_id + 1 : 0;
		break;
	case PREV_PATTERN:
		cur_pattern_id = (cur_pattern_id != 0) ? cur_pattern_id - 1 : groups[cur_group_id].nb_pattern - 1;
		break;
	case NEXT_GROUP:
		cur_group_id = (cur_group_id != nb_group - 1) ? cur_group_id + 1 : 0;
		cur_pattern_id = 0;
		break;
	case PREV_GROUP:
		cur_group_id = (cur_group_id != 0) ? cur_group_id - 1 : nb_group - 1;
		cur_pattern_id = 0;
		break;
	}
	x_offset = 0;
	y_offset = 0;
	z_offset = 0;
}

#define NB_STATE 10
int state_machine[NB_STATE] = {
	CUB_BTN_UP,
	CUB_BTN_UP,
	CUB_BTN_DOWN,
	CUB_BTN_DOWN,
	CUB_BTN_LEFT,
	CUB_BTN_RIGHT,
	CUB_BTN_LEFT,
	CUB_BTN_RIGHT,
	CUB_BTN_M_LEFT,
	CUB_BTN_M_RIGHT
};

bool status_update(CUB_Button b)
{
	//status = (state_machine[status] == b) ? status + 1 : 0;
	if (state_machine[status] == b) {
		status++;
	} else if (status > 0
			&& state_machine[status-1] == b) {
	} else {
		status = 0;
	}
	CUB_TextClear();
	CUB_TextHome();
	char score_string[16];
	my_itoa2(status, score_string);
	my_itoa2(b, score_string+8);
	CUB_TextPrint(score_string);
	if (status == NB_STATE) {
		status = 0;
		return true;
	}
	return false;
}

void screen_display_update()
{
	char group_number_display  [6 + 1]; // XX/XX  //
	char group_name_display    [SCREEN_WIDTH - 6 +1];
	char pattern_number_display[6 + 1];
	char pattern_name_display  [SCREEN_WIDTH - 6 +1];
	char screen                [SCREEN_WIDTH * 2 + 1];

	sprintf(group_number_display, "%"PRIu32"/%"PRIu32, cur_group_id+1, nb_group);
	strncpy(group_name_display, groups[cur_group_id].name, 6);
	group_name_display[SCREEN_WIDTH - 6] = '\0';

	sprintf(group_number_display, "%"PRIu32"/%"PRIu32, cur_pattern_id+1, groups[cur_group_id].nb_pattern);
	strncpy(pattern_name_display, groups[cur_group_id].patterns[cur_pattern_id].name, 6);
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

void pattern_display_update(int32_t x, int32_t y, int32_t z)
{
	CUB_LED_list_t *list = &(groups[cur_group_id].patterns[cur_pattern_id].data);
	x_offset += x;
	y_offset += y;
	z_offset += z;
	//screen_display_update();
	CUB_LEDs_clear();
	CUB_LED_t *cur_led = list->first;
	while (cur_led != NULL) {
		CUB_LEDs_switch_on(
				cur_led->x + x_offset,
				cur_led->y + y_offset,
				cur_led->z + z_offset);
		cur_led = cur_led->next;
	}
	CUB_LEDs_update_display();
}

void fill_list(pattern_t *p)
{
	CUB_LED_list_t *list = &(p->data);
	CUB_LED_list_init(list);
#ifdef FAKEDEMO
	int status = 0;
#else
	FIL *file = NULL;
	f_open(file, groups[cur_group_id].patterns[cur_pattern_id].path, FA_READ);
	int status = CUB_parser_parse_file(list, file);
	f_close(file);
#endif
	if (status == 1) {
		/* Do something */
	}
}

void application_init()
{
	group_and_pattern_init();
	//screen_display_update();
	pattern_display_update(0, 0, 0);
	status = 0;
}

void application_update(action_t action)
{
	group_and_pattern_update(action);
	//screen_display_update();
	pattern_display_update(0, 0, 0);
}

void CUB_ApplicationRun()
{
	application_init();
	CUB_EnableButtonRepeat(700, 80);

	CUB_LEDs_clear();
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("toto");
	CUB_Event event;
	int loop = 0;
	/* Infinite loop */
	for(;;) {
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
