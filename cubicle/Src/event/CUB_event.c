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

static osThreadId idlePushEvtTaskHandle;
static void _idlePushBtnEvent(void const * arg);

/**
 * Old button values
 */
static bool mButtonOldValue[CUB_BTN_LAST];

/**
 * Button repeat feature
 */
bool mBREnabled;
int32_t mBRDelay;
int32_t mBRInterval;
int32_t mBRTimer[CUB_BTN_LAST];


/**
 * Initialize the event module.
 */
void CUB_EventInit()
{
	// Create task to create button events.
	osThreadDef(IDLE_PUSH_EVT_TASK, _idlePushBtnEvent, osPriorityAboveNormal, 0, 128);
	idlePushEvtTaskHandle = osThreadCreate(osThread(IDLE_PUSH_EVT_TASK), NULL);

    // Init Queue
    eventQueue = xQueueCreate(MAX_EVENTS, sizeof(CUB_Event));

	// Init flags
	for(uint32_t i=0; i < CUB_BTN_LAST; i++)
		mButtonOldValue[i] = false;

	// Init button repeat feature
	mBREnabled = false;
	mBRDelay = 0;
	mBRInterval = 0;
	for(uint32_t i=0; i < CUB_BTN_LAST; i++)
		mBRTimer[i] = 0;
}

void CUB_EventQuit()
{
}


/**
 * Polls for currently pending events, and returns true if there are any pending
 * events, or false if there are none available. The next
 * event is removed from the queue and stored in 'event' parameter memory area.
 * This function can be blocked.
 */
bool CUB_PollEvent(CUB_Event * event)
{
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
    portBASE_TYPE res = xQueueSend(eventQueue, event, 0);
    return res == pdPASS;
}

/**
 * Enables or disables the button repeat rate.
 * 'delay' specifies how long the key must be pressed
 * before it begins repeating, it then repeats at the
 * speed specified by 'interval'.
 * Both 'delay' and 'interval' are expressed in milliseconds.
 * Setting delay to 0 disables key repeating completely.
 * The repeatition time can be not very accurate.
 */
void CUB_EnableButtonRepeat(uint16_t delay, uint16_t interval)
{
	if (delay == 0) {
		mBREnabled = false;
		return;
	}

	mBREnabled = true;
	mBRDelay = (int32_t)delay;
	mBRInterval = (int32_t)interval;
}


/**
 * Private
 */

inline static void _butEvent(CUB_Button id, CUB_EventType ev_type)
{
	CUB_Event event;
	event.type = ev_type;
	event.button.id = id;
	CUB_PushEvent(&event);
}


/**
 * Examine flags and create
 * corresponding events
 */
static void _idlePushBtnEvent(void const * arg)
{
    GPIO_TypeDef* ports[] = {
        CONFIG_BTN_UP_PORT,
        CONFIG_BTN_DOWN_PORT,
        CONFIG_BTN_LEFT_PORT,
        CONFIG_BTN_RIGHT_PORT,
        CONFIG_BTN_TOP_PORT,
        CONFIG_BTN_BOTTOM_PORT,
        CONFIG_BTN_MENU_LEFT_PORT,
        CONFIG_BTN_MENU_RIGHT_PORT,
        CONFIG_BTN_SUB_MENU_LEFT_PORT,
        CONFIG_BTN_SUB_MENU_RIGHT_PORT
    };
    uint16_t pins[] = {
        CONFIG_BTN_UP_PIN,
        CONFIG_BTN_DOWN_PIN,
        CONFIG_BTN_LEFT_PIN,
        CONFIG_BTN_RIGHT_PIN,
        CONFIG_BTN_TOP_PIN,
        CONFIG_BTN_BOTTOM_PIN,
        CONFIG_BTN_MENU_LEFT_PIN,
        CONFIG_BTN_MENU_RIGHT_PIN,
        CONFIG_BTN_SUB_MENU_LEFT_PIN,
        CONFIG_BTN_SUB_MENU_RIGHT_PIN
    };
	for(;;) {
		for(uint32_t i=0; i < CUB_BTN_LAST; i++) {
            bool set = (HAL_GPIO_ReadPin(ports[i],pins[i])==GPIO_PIN_SET);
#ifdef BUTTONS_ARE_ACTIVATED_AT_LOW_LEVEL 
			set = !set;
#endif
            if (!mButtonOldValue[i] && set) 
            {
                mButtonOldValue[i] = !mButtonOldValue[i];
				_butEvent(i, CUB_BUTTON_PRESSED);
				if (mBREnabled) {
					mBRTimer[i] = mBRDelay;
				}
            } else if (mButtonOldValue[i] && !set) {
                mButtonOldValue[i] = !mButtonOldValue[i];
				_butEvent(i, CUB_BUTTON_RELEASED);
				if (mBREnabled) {
					mBRTimer[i] = 0;
				}
            } else if (mBREnabled) {
				if (mBRTimer[i] > 0) {
					mBRTimer[i] -= BUTTON_POLLING_PERIOD;
					if (mBRTimer[i] <= 0) {
						_butEvent(i, CUB_BUTTON_RELEASED);
						_butEvent(i, CUB_BUTTON_PRESSED);
						mBRTimer[i] = mBRInterval;
					}
				}	
			}
		}
		osDelay(BUTTON_POLLING_PERIOD);
	}
}



