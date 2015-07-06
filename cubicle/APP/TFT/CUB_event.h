#ifndef _CUBICLE_EVENT_H_
#define _CUBICLE_EVENT_H_

#include <inttypes.h>
#include <stdbool.h>
#include "CUB_button.h"

/**
 * All possible event types
 */
typedef enum {
    CUB_NOEVENT = 0,
    CUB_BUTTON_PRESSED,
    CUB_BUTTON_RELEASED,

    CUB_NUM_EVENTS
} CUB_EventType;

/**
 * Button event
 */
typedef struct {
    uint8_t type;
    CUB_Button id;
} CUB_ButtonEvent;

/**
 * General event
 */
typedef union {
    uint8_t type;
    CUB_ButtonEvent button;
} CUB_Event;

/**
 * Initialize the event module.
 */
void CUB_EventInit();

/**
 * Polls for currently pending events, and returns true if there are any pending
 * events, or false if there are none available.  If 'event' is not NULL, the next
 * event is removed from the queue and stored in that memory area.
 */
bool CUB_PollEvent(CUB_Event * event);

/**
 * Add an event to the event queue.
 * This function returns true on success, or false if the event queue was full
 * or there was some other error.
 */
bool CUB_PushEvent(CUB_Event * event);

/**
 * Enables or disables the button repeat rate.
 * 'delay' specifies how long the key must be pressed
 * before it begins repeating, it then repeats at the
 * speed specified by 'interval'.
 * Both 'delay' and 'interval' are expressed in milliseconds.
 * Setting delay to 0 disables key repeating completely.
 * The repeatition time can be not very accurate.
 */
void CUB_EnableButtonRepeat(uint16_t delay, uint16_t interval);

#endif

