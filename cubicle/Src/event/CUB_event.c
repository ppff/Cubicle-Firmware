#include <stddef.h>
#include <string.h>

#include "cmsis_os.h"
#include "event/CUB_event.h"

#define MAX_EVENTS 1<<16

static uint16_t mSize = 0;
static CUB_Event mEvents[MAX_EVENTS];

static osThreadId idlePushEvtTaskHandle;
static void _idlePushBtnEvent(void const * arg);

/**
 * Initialize the event module.
 */
void CUB_EventInit()
{
	// Create task to create button events.
	osThreadDef(IDLE_PUSH_EVT_TASK, _idlePushBtnEvent, osPriorityBelowNormal, 0, 128);
	idlePushEvtTaskHandle = osThreadCreate(osThread(IDLE_PUSH_EVT_TASK), NULL);
}

/**
 * Polls for currently pending events, and returns true if there are any pending
 * events, or false if there are none available.  If 'event' is not NULL, the next
 * event is removed from the queue and stored in that memory area.
 */
bool CUB_PollEvent(CUB_Event * event)
{
    if (mSize == 0)
        return false;
    if (event != NULL) {
        memcpy(event, &mEvents[mSize-1], sizeof(CUB_Event));
    }
    mSize--;
    return true;
}

/**
 * Add an event to the event queue.
 * This function returns true on success, or false if the event queue was full
 * or there was some other error.
 */
bool CUB_PushEvent(CUB_Event * event)
{
    if (event == NULL)
        return true;
    if (mSize == MAX_EVENTS)
        return false;
    memcpy(&mEvents[mSize], event, sizeof(CUB_Event));
    mSize++;
    return true;
}

/**
 * Private
 */

/**
 * Flag when button is pressed
 */
static bool mButtonDown[CUB_BTN_LAST];
/**
 * Flag when button is released
 */
static bool mButtonUp[CUB_BTN_LAST];

/**
 * It handler when button pressed
 */
static void _itHdl_btnPressed(CUB_Button id)
{
    mButtonDown[id] = true;
}

/**
 * It handler when button released
 */
static void _itHdl_btnReleased(CUB_Button id)
{
	mButtonUp[id] = true;
}

/**
 * Examine flags and create
 * corresponding events
 */
static void _idlePushBtnEvent(void const * arg)
{
	CUB_Event event;
	for(;;) {
		for(int i=0; i < CUB_BTN_LAST; i++) {
			if (mButtonDown[i]) {
				mButtonDown[i] = 0;
				event.type = CUB_BUTTON_DOWN;
				event.button.id = i;
				CUB_PushEvent(&event);
			}
			if (mButtonUp[i]) {
				mButtonUp[i] = 0;
				event.type = CUB_BUTTON_UP;
				event.button.id = i;
				CUB_PushEvent(&event);
			}
		}
		osDelay(10);
	}
}

#include "stm32f4xx_hal.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint8_t val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
		_itHdl_btnPressed(CUB_BTN_UP);
}

