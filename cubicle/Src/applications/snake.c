#include "applications/snake.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "CUB.h"
#include "stm32f4xx_hal_conf.h"
#include "LEDs/CUB_LEDs.h"
#include "constant.h"
#include "CUB_point.h"
#include "CUB_point_list.h"

void inverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void my_itoa(int value, char str[]) 
{
	int i = 0;
	if (value >= 0) {
		do {
			str[i++] = value % 10 + '0';
		} while ((value /= 10) > 0);
		str[i] = '\0';
		inverse(str);
	} else {
		strcpy(str,"");
	}
}

typedef enum direction {
	PLUS_X=0,
	MINUS_X,
	PLUS_Y,
	MINUS_Y,
	PLUS_Z,
	MINUS_Z
} direction_t;


typedef struct snake {
	point_list_t body;
	direction_t direction;
	uint32_t size;
} snake_t;

void snake_init(snake_t *snake)
{
	point_list_init(&snake->body);
	snake->size = 0;
	for (uint32_t i=0; i<4; ++i) {
		point_t p = {3-i, 0, 0};
		point_list_add_element(&(snake->body), &p);
		CUB_LEDs_switch_on(p.x, p.y, p.z);
	}
	snake->direction = PLUS_X;
}

bool snake_consistent(snake_t *snake)
{
	point_list_element_t *cur = snake->body.first;
	cur = cur->next;
	while (cur != NULL) {
		if (point_equals(&(snake->body.first->p), &(cur->p))) {
			return false;
		}
		cur = cur->next;
	}
	return true;
}

void snake_increase(snake_t *s)
{
	point_list_add_element(&(s->body), &(s->body.last->p));
	s->size++;
}

void snake_free(snake_t *snake)
{
	point_list_free(&(snake->body));
}

void snake_move_forward(snake_t *snake)
{
	point_t *last  = &(snake->body.last->p);
	point_t *first = &(snake->body.first->p);
	CUB_LEDs_switch_off(last->x, last->y, last->z);
	point_copy(last, first);
	switch(snake->direction) {
	case PLUS_X:
		last->x += 1;
		if (last->x == SIZE_X)
			last->x = 0;
		break;
	case MINUS_X:
		if (last->x != 0) {
			last->x -= 1;
		} else {
			last->x = SIZE_X - 1;
		}
		break;
	case PLUS_Y:
		last->y += 1;
		if (last->y == SIZE_Y)
			last->y = 0;
		break;
	case MINUS_Y:
		if (last->y != 0) {
			last->y -= 1;
		} else {
			last->y = SIZE_Y - 1;
		}
		break;
	case PLUS_Z:
		last->z += 1;
		if (last->z == SIZE_Z)
			last->z = 0;
		break;
	case MINUS_Z:
		if (last->z != 0) {
			last->z -= 1;
		} else {
			last->z = SIZE_Z - 1;
		}
		break;
	}
	CUB_LEDs_switch_on(last->x, last->y, last->z);
	point_list_queue_to_head(&(snake->body));
}

void snake_display(snake_t *s)
{
	point_list_element_t *cur = s->body.first;
	while (cur != NULL) {
		CUB_LEDs_switch_on(cur->p.x, cur->p.y, cur->p.z);
		cur = cur->next;
	}
}


typedef struct food {
	point_t location;
} food_t;

void food_init(food_t *f)
{
	f->location.x = 4;
	f->location.y = 4;
	f->location.z = 4;
	CUB_LEDs_switch_on(f->location.x, f->location.y, f->location.z);
}

void food_new(food_t *f)
{
	CUB_LEDs_switch_off(f->location.x, f->location.y, f->location.z);
	f->location.x = (f->location.y + 5) % (SIZE_X);
	f->location.y = (f->location.z + 4) % (SIZE_Y);
	f->location.z = (f->location.x + f->location.y + 3) % (SIZE_Z);
	CUB_LEDs_switch_on(f->location.x, f->location.y, f->location.z);
}

int manhattan_distance(snake_t *s, food_t *f)
{
	uint32_t dx = (f->location.x > s->body.first->p.x)?
		(f->location.x - s->body.first->p.x):
		(s->body.first->p.x - f->location.x);
	uint32_t dy = (f->location.y > s->body.first->p.y)?
		(f->location.y - s->body.first->p.y):
		(s->body.first->p.y - f->location.y);
	uint32_t dz = (f->location.z > s->body.first->p.z)?
		(f->location.z - s->body.first->p.z):
		(s->body.first->p.z - f->location.z);
	return (dx + dy + dz);
}

/**
 * Saved score
 */
static uint32_t best_score = 0;

void CUB_ApplicationRun_snake()
{
	CUB_TextHome();
	CUB_TextPrint("Snake!");
	CUB_LEDs_clear();

	CUB_Event event;
	snake_t snake;
	food_t food;
	uint32_t score;
	new_game:
	score = 0;
	snake_init(&snake);
	food_init(&food);
	food_new(&food);
	CUB_TextClear();
	CUB_TextPrintf("       SNAKE!       \nHIGHSCORE : %i", best_score);
	CUB_Sleep(2000);
	CUB_TextClear();
	CUB_TextHome();
	CUB_TextPrintf("SCORE     %i\nHIGHSCORE     %i", score, best_score);
	uint32_t md = manhattan_distance(&snake, &food);
	uint32_t nb_step = 0;
	for(;;) {
		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						if (snake.direction != MINUS_Z)
							snake.direction = PLUS_Z;
						break;
					case CUB_BTN_DOWN:
						if (snake.direction != PLUS_Z)
							snake.direction = MINUS_Z;
						break;
					case CUB_BTN_LEFT:
						if (snake.direction != PLUS_Y)
							snake.direction = MINUS_Y;
						break;
					case CUB_BTN_RIGHT:
						if (snake.direction != MINUS_Y)
							snake.direction = PLUS_Y;
						break;
					case CUB_BTN_TOP:
						if (snake.direction != PLUS_X)
							snake.direction = MINUS_X;
						break;
					case CUB_BTN_BOTTOM:
						if (snake.direction != MINUS_X)
							snake.direction = PLUS_X;
						break;
					case CUB_BTN_M_LEFT:
					case CUB_BTN_M_RIGHT:
					case CUB_BTN_SM_LEFT:
					case CUB_BTN_SM_RIGHT:
						if (score > best_score)
							best_score = score;
						snake_free(&snake);
						return;
						break;
					default:
						;
				}
			} else if (event.type == CUB_BUTTON_RELEASED) {
				switch (event.button.id) {
					case CUB_BTN_UP:
						break;
					default:
						;
				}
			}
		}
		snake_move_forward(&snake);
		nb_step++;
		if (!snake_consistent(&snake)) {
			for (uint32_t i=0; i<4; ++i) {
				CUB_LEDs_clear();
				snake_display(&snake);
				CUB_LEDs_update_display();
				CUB_Sleep(250);
				CUB_LEDs_clear();
				CUB_LEDs_update_display();
				CUB_Sleep(250);
			}
			if (score > best_score)
				best_score = score;
			CUB_TextClear();
			CUB_TextPrintf("<YES   REPLAY?   NO>\nSCORE:%i   BEST:%i", score, best_score);
			CUB_Sleep(1000);
			while(1) {
				CUB_PollEvent(&event);
				if (event.type == CUB_BUTTON_PRESSED) {
					switch(event.button.id) {
						case CUB_BTN_M_LEFT:
							goto new_game;
							break;
						case CUB_BTN_M_RIGHT:
							goto end_game;
							break;
						default:
							;
					}
				}
			}
			end_game:
			snake_free(&snake);
			return;
		}
		if (point_list_is_in(&(snake.body), &(food.location))) {
			snake_increase(&snake);
			uint32_t step_diff = nb_step - md;
			uint32_t tmp = (step_diff < 20) ? (20 - step_diff) : 1;
			score += snake.size + tmp;

			CUB_TextClear();
			CUB_TextHome();
			CUB_TextPrintf("SCORE     %i\nHIGHSCORE     %i", score, best_score);

			while (point_list_is_in(&(snake.body), &(food.location))) {
				food_new(&food);
				md = manhattan_distance(&snake, &food);
				nb_step = 0;
			}
		}
		CUB_LEDs_update_display();
		CUB_Sleep(300 - snake.size * 10);
	}
}

