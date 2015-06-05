#include <stddef.h>
#include "api/CUB_api.h"


/**
 * Initialiaze the API module
 */
void CUB_ApiInit()
{

}

/**
 * Is API started ?
 * The API is started when we 
 * receive our first command
 */
bool CUB_ApiIsStarted()
{
	return false;
}

/**
 * Pull the next data as api command.
 * It returns 'true' when there is a cmd
 * to treat. Else 'false'.
 * If 'cmd' is not null, the command
 * is copied into that memory area.
 */
bool CUB_ApiGetNextCommand(CUB_ApiCommand * cmd)
{
	if (cmd != NULL) {
		*cmd = CUB_API_NO_CMD;
	}

	return false;
}


/**
 * Pull the next data as data for previous
 * command.
 */
uint8_t CUB_ApiGetNextUint8()
{
	return 0;
}

/**
 * Pull the next data as data for previous
 * command.
 */
int8_t CUB_ApiGetNextInt8()
{
	return 0;
}

/**
 * Pull the next data as data for previous
 * command.
 */
uint16_t CUB_ApiGetNextUint16()
{
	return 0;
}

/**
 * Pull the next data as data for previous
 * command.
 */
int16_t CUB_ApiGetNextInt16()
{
	return 0;
}

/**
 * Pull the next data as data for previous
 * command.
 */
uint32_t CUB_ApiGetNextUint32()
{
	return 0;
}

/**
 * Pull the next data as data for previous
 * command.
 */
int32_t CUB_ApiGetNextInt32()
{
	return 0;
}

