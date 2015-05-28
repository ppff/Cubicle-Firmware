#include "cmsis_os.h"
#include "CUB.h"

#ifndef __weak
	#define __weak __attribute__((weak))
#endif

__weak void CUB_ApplicationRun()
{
	/* Note: this function should be redefined
 	 * by the framework user in other file (e.g. application.c)
 	 */
}

/**
 * Initialize Cubicle
 */
void CUB_Init()
{
	CUB_EventInit();
	CUB_TextInit(2, 20);
	CUB_LEDs_init();
}

/**
 * Free Cubicle ressources
 */
void CUB_Quit()
{
	CUB_TextQuit();
	CUB_EventQuit();
}

/**
 * Sleep for milliseconds
 */
void CUB_Sleep(uint32_t milli)
{
	osDelay(milli);
}

