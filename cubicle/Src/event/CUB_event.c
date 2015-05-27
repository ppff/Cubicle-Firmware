#include <stddef.h>
#include <string.h>

#include "cmsis_os.h"
#include "event/CUB_event.h"

#define MAX_EVENTS 1<<16

static uint16_t mSize = 0;
static CUB_Event mEvents[MAX_EVENTS];

static osThreadId idlePushEvtTaskHandle;
static void _idlePushBtnEvent(void const * arg);

static osMutexId _mutex_events;

/**
 * Flag when button is pressed
 */
static bool mButtonDown[CUB_BTN_LAST];
/**
 * Flag when button is released
 */
static bool mButtonUp[CUB_BTN_LAST];
/**
 * Button current states
 */
static bool mButtonState[CUB_BTN_LAST];

/**
 * Initialize the event module.
 */
void CUB_EventInit()
{
	// Create task to create button events.
	osThreadDef(IDLE_PUSH_EVT_TASK, _idlePushBtnEvent, osPriorityAboveNormal, 0, 128);
	idlePushEvtTaskHandle = osThreadCreate(osThread(IDLE_PUSH_EVT_TASK), NULL);

	// Create mutex to share event structure.
	osMutexDef(MUTEX_EVENTS);
	_mutex_events = osMutexCreate(osMutex(MUTEX_EVENTS));

	for(uint32_t i=0; i < CUB_BTN_LAST; i++) {
		mButtonDown[i] = false;
		mButtonUp[i] = false;
		mButtonState[i] = false;
	}
}

void CUB_EventQuit()
{
	osMutexDelete(_mutex_events);
}

static inline void takeMutex()
{
	while (osMutexWait(_mutex_events, 0) != osOK);
}

static inline void releaseMutex()
{
	osMutexRelease(_mutex_events);
}

/**
 * Polls for currently pending events, and returns true if there are any pending
 * events, or false if there are none available.  If 'event' is not NULL, the next
 * event is removed from the queue and stored in that memory area.
 * This function can be blocked.
 */
bool CUB_PollEvent(CUB_Event * event)
{
    if (mSize == 0)
        return false;
	takeMutex();
    if (event != NULL) {
        memcpy(event, &mEvents[mSize-1], sizeof(CUB_Event));
    }
    mSize--;
	releaseMutex();
    return true;
}

/**
 * Add an event to the event queue.
 * This function returns true on success, or false if the event queue was full
 * or there was some other error.
 * This function can be blocked.
 */
bool CUB_PushEvent(CUB_Event * event)
{
	takeMutex();
    if (event == NULL) {
		releaseMutex();
        return true;
	}
    if (mSize == MAX_EVENTS) {
		releaseMutex();
        return false;
	}
    memcpy(&mEvents[mSize], event, sizeof(CUB_Event));
    mSize++;
	releaseMutex();
    return true;
}

/**
 * Private
 */


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
/*static*/ void _itHdl_btnReleased(CUB_Button id)
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
		for(uint32_t i=0; i < CUB_BTN_LAST; i++) {
			if (mButtonDown[i]) {
				mButtonDown[i] = false;
				event.type = CUB_BUTTON_DOWN;
				event.button.id = i;
				CUB_PushEvent(&event);
			}
			if (mButtonUp[i]) {
				mButtonUp[i] = false;
				event.type = CUB_BUTTON_UP;
				event.button.id = i;
				CUB_PushEvent(&event);
			}
		}
		osDelay(50);
	}
}

#include "stm32f4xx_hal.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint8_t val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
		_itHdl_btnPressed(CUB_BTN_UP);
	/*val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_DOWN);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_LEFT);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_RIGHT);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_TOP);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_BOTTOM);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_M_LEFT);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_M_RIGHT);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_SM_LEFT);
	val = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if (val)
	    _itHdl_btnPressed(CUB_BTN_SM_RIGHT);
	*/
}

