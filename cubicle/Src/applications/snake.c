#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "CUB.h"
#include "stm32f4xx_hal_conf.h"
#include "LEDs/CUB_LEDs.h"
#include "constant.h"
#include "CUB_point.h"
#include "CUB_point_list.h"

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
} snake_t;

void snake_init(snake_t *snake)
{
	point_list_init(&snake->body);
	for (uint32_t i=0; i<4; ++i) {
		point_t p = {3-i, 0, 0};
		point_list_add_element(&(snake->body), &p);
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

void snake_free(snake_t *snake)
{
	point_list_free(&(snake->body));
}

void snake_move_forward(snake_t *snake)
{
	point_t *last  = &(snake->body.last->p);
	point_t *first = &(snake->body.first->p);
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
}

void food_new(food_t *f)
{
	CUB_LEDs_switch_off(f->location.x, f->location.y, f->location.z);
	f->location.x = f->location.y + 5 % SIZE_X;
	f->location.y = f->location.z + 4 % SIZE_Y;
	f->location.z = f->location.x + f->location.y + 3 % SIZE_Z;
}

void food_display(food_t *f)
{
	CUB_LEDs_toggle(f->location.x, f->location.y, f->location.z);
}

void CUB_ApplicationRun()
{
	CUB_TextHome();
	CUB_TextPrint("Snake!");

	CUB_Event event;
	while (true) {
		snake_t snake;
		food_t food;
		snake_init(&snake);
		food_init(&food);
		food_new(&food);
		for(;;) {
			while (CUB_PollEvent(&event)) {
				if (event.type == CUB_BUTTON_PRESSED) {
					switch (event.button.id) {
						case CUB_BTN_UP:
							if (snake.direction != PLUS_X)
								snake.direction = MINUS_X;
							break;
						case CUB_BTN_DOWN:
							if (snake.direction != MINUS_X)
								snake.direction = PLUS_X;
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
							if (snake.direction != MINUS_Z)
								snake.direction = PLUS_Z;
							break;
						case CUB_BTN_BOTTOM:
							if (snake.direction != PLUS_Z)
								snake.direction = MINUS_Z;
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
						default:
							;
					}
				}
			}
			snake_move_forward(&snake);
			if (!snake_consistent(&snake)) {
				snake_free(&snake);
				break;
			}
			CUB_LEDs_clear();
			snake_display(&snake);
			food_display(&food);
			if (point_list_is_in(&(snake.body), &(food.location))) {
				point_list_add_element(&(snake.body), &(snake.body.last->p));
				food_new(&food);
			}
			CUB_LEDs_update_display();
			CUB_Sleep(250);
		}
	}
	CUB_LEDs_free();
}

