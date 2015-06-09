#include <string.h>
#include <stdio.h>

#include "CUB.h"
#include "LEDs/CUB_LEDs.h"
#include "CUB_parser.h"
#include "applications/crystal_structure/CUB_LED_list.h"
#include "applications/snake.h"
#include "constant.h"

#define SCREEN_WIDTH 32
#define BTN_REPEAT_DELAY 700
#define BTN_REPEAT_INTERVAL 80

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

void initFromMySPI()
{

}

void group_and_pattern_init()
{
#ifdef FAKEDEMO
#include "files.h"
#else
	// Initialize pattern->pf to NULL
	
	initFromMySPI();
#endif
	x_offset = 0;
	y_offset = 0;
	z_offset = 0;
}

void group_and_pattern_update(action_t action)
{
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

void group_and_patter_free()
{
	// Free every pattern->pf if not NULL
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
	//CUB_TextPrint(score_string);
	if (status == NB_STATE) {
		status = 0;
		return true;
	}
	return false;
}

void screen_display_update()
{
	CUB_TextClear();
    CUB_TextPrintf("%i/%i", cur_group_id+1, nb_group);
	CUB_TextPrintRight(groups[cur_group_id].name, 0);
	CUB_TextPrintf("\n");
	CUB_TextPrintf("%i/%i",cur_pattern_id+1, groups[cur_group_id].nb_pattern);
	CUB_TextPrintRight(groups[cur_group_id].patterns[cur_pattern_id].name, 1);
}

void pattern_display_update(int32_t x, int32_t y, int32_t z)
{
	CUB_LED_list_t *list = &(groups[cur_group_id].patterns[cur_pattern_id].data);
	x_offset += x;
	y_offset += y;
	z_offset += z;
	screen_display_update();
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
#ifdef FAKEDEMO
	int status = 0;
#else
	//CUB_parsed_file_t *pf = MALLOC(sizeof(CUB_parsed_file_t));
	//CUB_LED_list_init((CUB_LED_list_t *)(&(pf->led_list)));
	CUB_LED_list_init(&(p->data));
	FIL *file = NULL;
	f_open(file, groups[cur_group_id].patterns[cur_pattern_id].path, FA_READ);
	int status = CUB_parser_parse_file(pf, file);
	f_close(file);
#endif
	if (status == 1) {
		/* Do something */
	}
}

void application_init()
{
	group_and_pattern_init();
	screen_display_update();
	pattern_display_update(0, 0, 0);
	status = 0;
}

void application_update(action_t action)
{
	group_and_pattern_update(action);
	screen_display_update();
	pattern_display_update(0, 0, 0);
}

void CUB_ApplicationRun()
{
	application_init();
	CUB_EnableButtonRepeat(BTN_REPEAT_DELAY, BTN_REPEAT_INTERVAL);

	CUB_LEDs_clear();
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrint("Crystallo");
	CUB_Event event;
	uint32_t best_score;
	/* Infinite loop */
	for(;;) {
		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				if (status_update(event.button.id)) {
					CUB_EnableButtonRepeat(0, 0); // disable btn repeat
					best_score = CUB_ApplicationRun_snake(best_score);
					CUB_EnableButtonRepeat(BTN_REPEAT_DELAY, BTN_REPEAT_INTERVAL);
				}
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
			// Check if SD card is still in slot.
		}

		CUB_Sleep(50);
	}
}
