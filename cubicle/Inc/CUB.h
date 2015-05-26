#ifndef _CUB_H_
#define _CUB_H_

/**
 * Entry point of the application.
 * Should be redefined by the user.
 */
void CUB_ApplicationRun();

#include "event/CUB_event.h"
#include "text/CUB_text.h"
#include "display/CUB_display.h"

/**
 * Initialize Cubicle
 */
void CUB_Init();

/**
 * Free Cubicle ressources
 */
void CUB_Quit();

/**
 * Sleep for milliseconds
 */
void CUB_Sleep(uint32_t milli);

#endif
