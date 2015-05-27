#include <stddef.h>
#include <string.h>

#include "cmsis_os.h"
#include "event/CUB_event.h"

#define MAX_EVENTS 1<<8

/**
 * Circular buffer
 */
static CUB_Event mEvents[MAX_EVENTS];
static uint16_t mWriter;
static uint16_t mReader;
static uint16_t mSize;

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

	// Init circular buffer
	mWriter = mReader = mSize = 0;

	// Init flags
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
    if (mSize == 0) {
        return false;
	}

	takeMutex();
	if (event != NULL) {
		memcpy(event, &mEvents[mReader], sizeof(CUB_Event));
    }
	mReader = (mReader+1) % MAX_EVENTS;
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
    if (event == NULL) {
        return true;
	}

	bool ret = false;
	takeMutex();
    if (mSize == MAX_EVENTS) {
        ret = false;
	} else {
    	memcpy(&mEvents[mWriter], event, sizeof(CUB_Event));
		mWriter = (mWriter+1) % MAX_EVENTS;
    	mSize++;
		ret = true;
	}
	releaseMutex();
    return ret;
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
	mButtonState[id] = true;
}

/**
 * It handler when button released
 */
static void _itHdl_btnReleased(CUB_Button id)
{
	mButtonUp[id] = true;
	mButtonState[id] = false;
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

static inline void treatBtnChange(GPIO_TypeDef* port, uint16_t pin, uint32_t buttonId)
{
	uint8_t val = HAL_GPIO_ReadPin(port, pin);
	if (mButtonState[buttonId] && !val) {
		// button was pressed and is now released
		_itHdl_btnReleased(buttonId);
	} else if (!mButtonState[buttonId] && val) {
		// button was released and is now pressed
		_itHdl_btnPressed(buttonId);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	treatBtnChange(GPIOA, GPIO_PIN_0, CUB_BTN_UP);
	//treatBtnChange(GPIOA, GPIO_PIN_0, CUB_BTN_UP);
}

