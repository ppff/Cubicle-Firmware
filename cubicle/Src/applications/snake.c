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
	point_list_t *body;
	direction_t direction;
} snake_t;

void snake_init(snake_t *snake)
{
	snake->body = MALLOC(sizeof(point_list_t));
	for (uint32_t i=0; i<4; ++i) {
		point_t p = {3-i, 0, 0};
		point_list_add_element(snake->body, &p);
	}
}

void snake_free(snake_t *snake)
{
	point_list_free(snake->body);
}

void snake_move_forward(snake_t *snake)
{
	switch(snake->direction) {
	case PLUS_X:
		snake->body->last->p.x = snake->body->first->p.x + 1;
		snake->body->last->p.y = snake->body->first->p.y;
		snake->body->last->p.z = snake->body->first->p.z;
		break;
	case MINUS_X:
		snake->body->last->p.x = snake->body->first->p.x - 1;
		snake->body->last->p.y = snake->body->first->p.y;
		snake->body->last->p.z = snake->body->first->p.z;
		break;
	case PLUS_Y:
		snake->body->last->p.x = snake->body->first->p.x;
		snake->body->last->p.y = snake->body->first->p.y + 1;
		snake->body->last->p.z = snake->body->first->p.z;
		break;
	case MINUS_Y:
		snake->body->last->p.x = snake->body->first->p.x;
		snake->body->last->p.y = snake->body->first->p.y - 1;
		snake->body->last->p.z = snake->body->first->p.z;
		break;
	case PLUS_Z:
		snake->body->last->p.x = snake->body->first->p.x;
		snake->body->last->p.y = snake->body->first->p.y;
		snake->body->last->p.z = snake->body->first->p.z + 1;
		break;
	case MINUS_Z:
		snake->body->last->p.x = snake->body->first->p.x;
		snake->body->last->p.y = snake->body->first->p.y;
		snake->body->last->p.z = snake->body->first->p.z - 1;
		break;
	}
	point_list_element_t *previous_first = snake->body->first;
	snake->body->last = snake->body->last->prev;
	snake->body->last->next = NULL;
	snake->body->first = snake->body->last;
	snake->body->first->next = previous_first;
	snake->body->first->prev = NULL;
}

void snake_display(snake_t *s)
{
	point_list_element_t *cur = s->body->first;
	while (cur != NULL) {
		CUB_LEDs_switch_on(cur->p.x, cur->p.y, cur->p.z);
		cur = cur->next;
	}
}


typedef struct food {
	point_t location;
} food_t;

void food_new(food_t *f)
{
	f->location.x = f->location.y + 5 % SIZE_X;
	f->location.y = f->location.z + 4 % SIZE_Y;
	f->location.z = f->location.x + f->location.y + 3 % SIZE_Z;
}


void CUB_ApplicationRun()
{
	CUB_TextHome();
	CUB_TextPrint("Snake!");

	CUB_Event event;
	snake_t snake;
	CUB_LEDs_init();
	snake_init(&snake);
	for(;;) {
		while (CUB_PollEvent(&event)) {
			if (event.type == CUB_BUTTON_PRESSED) {
				switch (event.button.id) {
				case CUB_BTN_UP:
					snake.direction = MINUS_X;
					break;
				case CUB_BTN_DOWN:
					snake.direction = PLUS_X;
					break;
				case CUB_BTN_LEFT:
					snake.direction = MINUS_Y;
					break;
				case CUB_BTN_RIGHT:
					snake.direction = PLUS_Y;
					break;
				case CUB_BTN_TOP:
					snake.direction = PLUS_Z;
					break;
				case CUB_BTN_BOTTOM:
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
			snake_move_forward(&snake);
			CUB_LEDs_clear();
			snake_display(&snake);
			CUB_LEDs_update_display();
			CUB_Sleep(500);
		}
	}
	snake_free(&snake);
	CUB_LEDs_free();
}

