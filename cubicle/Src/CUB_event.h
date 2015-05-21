#ifndef _CUBICLE_EVENT_H_
#define _CUBICLE_EVENT_H_

#include <inttypes.h>
#include <stdbool.h>

/**
 * All possible event types
 */
typedef enum {
    CUB_NOEVENT = 0,
    CUB_BUTTON_DOWN,
    CUB_BUTTON_UP,
    CUB_NUM_EVENTS
} CUB_EventType;

/**
 * Button event
 */
typedef struct {
    uint8_t type;
    uint8_t id;
} CUB_ButtonEvent;

/**
 * General event
 */
typedef union {
    uint8_t type;
    CUB_ButtonEvent button;
} CUB_Event;

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

#endif
