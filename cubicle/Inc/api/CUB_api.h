#ifndef _CUBICLE_API_H_
#define _CUBICLE_API_H_

#include <stdbool.h>
#include <inttypes.h>

/**
 * API commands
 */
typedef enum {
	/** No command */
	CUB_API_NO_CMD = 0,

	/** Reset API state (future use).
	 * Can be used to start API communication */
	CUB_API_RESET,

	/** Close the API communication */
	CUB_API_CLOSE,

	CUB_API_GET_VERSION,

	CUB_API_CLEAR_LEDS,
	CUB_API_LED_ON,
	CUB_API_LED_OFF,
	CUB_API_UP_LED_DISPLAY,
	
	CUB_API_CLEAR_LCD,
	CUB_API_SET_CURSOR,
	CUB_API_PRINT,
	// ...
	
	CUB_API_ENABLE_BTN_REPEAT,

	CUB_API_PUSH_EVENT,

	CUB_API_NB_COMMANDS // internal use
} CUB_ApiCommand;

/**
 * Initialiaze the API module
 */
void CUB_ApiInit();

/**
 * Is API started ?
 * The API is started when we 
 * receive our first command
 */
bool CUB_ApiIsStarted();

/**
 * Pull the next data as api command.
 * It returns 'true' when there is a cmd
 * to treat. Else 'false'.
 * If 'cmd' is not null, the command
 * is copied into that memory area.
 */
bool CUB_ApiGetNextCommand(CUB_ApiCommand * cmd);

/**
 * Pull the next data as data for previous
 * command.
 */
uint8_t CUB_ApiGetNextUint8();

/**
 * Pull the next data as data for previous
 * command.
 */
int8_t CUB_ApiGetNextInt8();

/**
 * Pull the next data as data for previous
 * command.
 */
uint16_t CUB_ApiGetNextUint16();

/**
 * Pull the next data as data for previous
 * command.
 */
int16_t CUB_ApiGetNextInt16();

/**
 * Pull the next data as data for previous
 * command.
 */
uint32_t CUB_ApiGetNextUint32();

/**
 * Pull the next data as data for previous
 * command.
 */
int32_t CUB_ApiGetNextInt32();

void CUB_ApiSend(const char * msg);

void CUB_ApiSend2(const char * msg, const char * msg2)
{
	CUB_ApiSend(msg);
	CUB_ApiSend(msg2);
}

void CUB_ApiSend3(const char * msg, const char * msg2, const char * msg3)
{
	CUB_ApiSend2(msg, msg2);
	CUB_ApiSend(msg3);
}

#endif
