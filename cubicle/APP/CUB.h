#ifndef _CUB_H_
#define _CUB_H_

/**
 * Entry point of the application.
 * Should be redefined by the user.
 */
void CUB_ApplicationRun();

#include "CUB_event.h"
#include "CUB_text.h"
#include "CUB_LEDs.h"
#include "CUB_fs.h"

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