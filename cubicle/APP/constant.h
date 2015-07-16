#ifndef _CUBICLE_CONSTANTS_H_
#define _CUBICLE_CONSTANTS_H_

#define CUBICLE_VERSION 1
#define CUBICLE_VERSION_TXT "1"

/*
 * If you want to use a LENGTH >= 16 LEDs, you will have to update the type
 * definition of "line_t" in led.h to uint32_t or more.
 */
#define SIZE_X 9

#define SIZE_Y 9

#define SIZE_Z 9

#define FS_GPIO_PORT GPIOC
#define FS_GPIO_CLK_PIN GPIO_PIN_1
#define FS_GPIO_MOSI_PIN GPIO_PIN_2
#define FS_GPIO_MISO_PIN GPIO_PIN_3

/**
 * Define relation between button state 
 * and electrical value.
 * Value can be 0 or 1
 */
#define BUTTONS_ARE_ACTIVATED_AT_LOW_LEVEL 1

/**
 * Time to sleep (in ms) between
 * two polling iteration.
 */
#define BUTTON_POLLING_PERIOD 40

/**
 * Button pins configuration
 */

#define CONFIG_BTN_TOP_PORT GPIOE
#define CONFIG_BTN_TOP_PIN GPIO_PIN_7

#define CONFIG_BTN_BOTTOM_PORT GPIOE
#define CONFIG_BTN_BOTTOM_PIN GPIO_PIN_8

#define CONFIG_BTN_UP_PORT GPIOB
#define CONFIG_BTN_UP_PIN GPIO_PIN_10

#define CONFIG_BTN_LEFT_PORT GPIOE
#define CONFIG_BTN_LEFT_PIN GPIO_PIN_15

#define CONFIG_BTN_DOWN_PORT GPIOB
#define CONFIG_BTN_DOWN_PIN GPIO_PIN_11

#define CONFIG_BTN_RIGHT_PORT GPIOG
#define CONFIG_BTN_RIGHT_PIN GPIO_PIN_1

#define CONFIG_BTN_MENU_LEFT_PORT GPIOE
#define CONFIG_BTN_MENU_LEFT_PIN GPIO_PIN_9

#define CONFIG_BTN_MENU_RIGHT_PORT GPIOE
#define CONFIG_BTN_MENU_RIGHT_PIN GPIO_PIN_12

#define CONFIG_BTN_SUB_MENU_RIGHT_PORT GPIOE
#define CONFIG_BTN_SUB_MENU_RIGHT_PIN GPIO_PIN_14

#define CONFIG_BTN_SUB_MENU_LEFT_PORT GPIOE
#define CONFIG_BTN_SUB_MENU_LEFT_PIN GPIO_PIN_13



#ifdef STANDARD_COMPILATION
#include <stdlib.h>
#define MALLOC malloc
#define FREE   free
#else
#include "FreeRTOS.h"
#define MALLOC pvPortMalloc
#define FREE   vPortFree
#endif // STANDARD_COMPILATION

#endif // _CUBICLE_CONSTANTS_H_