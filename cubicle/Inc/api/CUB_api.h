#ifndef _CUBICLE_API_H_
#define _CUBICLE_API_H_

#include <stdbool.h>

/**
 * API commands
 */
typedef enum {
	CUB_API_NO_CMD = 0,
	CUB_API_GET_VERSION,

	CUB_API_CLEAR_LEDS,
	CUB_API_LED_ON,
	CUB_API_LED_OFF,
	CUB_API_UP_LED_DISPLAY,
	
	CUB_API_CLEAR_LCD,
	CUB_API_SET_CURSOR,
	CUB_API_PRINT,
	// ...
	
	CUB_API_PUSH_EVENT,

	CUB_API_NB_COMMANDS // internal use
} CUB_ApiCommand;

/**
 * Pull the next data as api command.
 * It returns 'true' when there is a cmd
 * to treat. Else 'false'.
 * If 'cmd' is not null, the command
 * is copied into that memory area.
 */
bool CUB_ApiGetNextCommand(CUB_ApiCommand * cmd);

#endif
