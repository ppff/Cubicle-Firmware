#include <stddef.h>
#include <string.h>

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"
#include "event/CUB_event.h"
#include "constant.h"
#include "queue.h"

#define MAX_EVENTS (1<<8)

/**
 * Define virtual state in fonction of
 * electric state.
 */

/**
 * using a FreeRTOS queue instead
 */
xQueueHandle eventQueue;

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
static bool mButtonWasPressed[CUB_BTN_LAST];
/**
 * Flag when button is released
 */
static bool mButtonWasReleased[CUB_BTN_LAST];
/**
 * Old button values
 */
static bool mButtonOldValue[CUB_BTN_LAST];


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

    // Init Queue
    eventQueue = xQueueCreate(MAX_EVENTS, sizeof(CUB_Event));

	// Init circular buffer
	mWriter = mReader = mSize = 0;

	// Init flags
	for(uint32_t i=0; i < CUB_BTN_LAST; i++) {
		mButtonWasPressed[i] = false;
		mButtonWasReleased[i] = false;
		mButtonOldValue[i] = false;
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
    //if (mSize == 0) {
	//	if (event != NULL) {
	//		event->type = CUB_NOEVENT;
	//	}
    //    return false;
	//}

	//takeMutex();
	//if (event != NULL) {
	//	memcpy(event, &mEvents[mReader], sizeof(CUB_Event));
    //}
	//mReader = (mReader+1) % MAX_EVENTS;
	//mSize--;
	//releaseMutex();
    portBASE_TYPE res = xQueueReceive(eventQueue, event, 0);
    return res == pdPASS;
}

/**
 * Add an event to the event queue.
 * This function returns true on success, or false if the event queue was full
 * or there was some other error.
 * This function can be blocked.
 */
bool CUB_PushEvent(CUB_Event * event)
{
    //if (event == NULL) {
    //    return true;
	//}

	//bool ret = false;
	//takeMutex();
    //if (mSize == MAX_EVENTS) {
    //    ret = false;
	//} else {
    //	memcpy(&mEvents[mWriter], event, sizeof(CUB_Event));
	//	mWriter = (mWriter+1) % MAX_EVENTS;
    //	mSize++;
	//	ret = true;
	//}
	//releaseMutex();
    portBASE_TYPE res = xQueueSend(eventQueue, event, 0);
    return res == pdPASS;
}

/**
 * Private
 */

/**
 * Examine flags and create
 * corresponding events
 */
static void _idlePushBtnEvent(void const * arg)
{
	CUB_Event event;
	for(;;) {
		for(uint32_t i=0; i < CUB_BTN_LAST; i++) {
			if (mButtonWasPressed[i]) {
					mButtonWasPressed[i] = false;
					event.type = CUB_BUTTON_PRESSED;
					event.button.id = i;
					CUB_PushEvent(&event);
			}
			if (mButtonWasReleased[i]) {
					mButtonWasReleased[i] = false;
					event.type = CUB_BUTTON_RELEASED;
					event.button.id = i;
					CUB_PushEvent(&event);
			}
		}
		osDelay(50);
	}
}



/**
 * 
 */
static inline void treatBtnChange(GPIO_TypeDef* port, uint16_t pin, uint32_t btnId)
{
	bool val = (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET);
#if BUTTONS_ARE_ACTIVATED_AT_LOW_LEVEL
	val = !val;
#endif
	if (!mButtonOldValue[btnId] && val) { // virtual rising edge
		mButtonWasPressed[btnId] = true;
	} else if (mButtonOldValue[btnId] && !val) { // virtual falling edge
		mButtonWasReleased[btnId] = true;
	}
	mButtonOldValue[btnId] = val;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	treatBtnChange(CONFIG_BTN_TOP_PORT,    CONFIG_BTN_TOP_PIN,    CUB_BTN_TOP);
	treatBtnChange(CONFIG_BTN_BOTTOM_PORT, CONFIG_BTN_BOTTOM_PIN, CUB_BTN_BOTTOM);
	treatBtnChange(CONFIG_BTN_UP_PORT,     CONFIG_BTN_UP_PIN,     CUB_BTN_UP);
	treatBtnChange(CONFIG_BTN_LEFT_PORT,   CONFIG_BTN_LEFT_PIN,   CUB_BTN_LEFT);
	treatBtnChange(CONFIG_BTN_DOWN_PORT,   CONFIG_BTN_DOWN_PIN,   CUB_BTN_DOWN);
	treatBtnChange(CONFIG_BTN_RIGHT_PORT,  CONFIG_BTN_RIGHT_PIN,  CUB_BTN_RIGHT);
	treatBtnChange(CONFIG_BTN_MENU_LEFT_PORT,      CONFIG_BTN_MENU_LEFT_PIN,      CUB_BTN_M_LEFT);
	treatBtnChange(CONFIG_BTN_MENU_RIGHT_PORT,     CONFIG_BTN_MENU_RIGHT_PIN,     CUB_BTN_M_RIGHT);
	treatBtnChange(CONFIG_BTN_SUB_MENU_LEFT_PORT,  CONFIG_BTN_SUB_MENU_LEFT_PIN,  CUB_BTN_SM_LEFT);
	treatBtnChange(CONFIG_BTN_SUB_MENU_RIGHT_PORT, CONFIG_BTN_SUB_MENU_RIGHT_PIN, CUB_BTN_SM_RIGHT);
}

