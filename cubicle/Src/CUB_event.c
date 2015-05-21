#include <stddef.h>
#include <string.h>

#include "CUB_event.h"

#define MAX_EVENTS 1<<16

uint16_t mSize = 0;
CUB_Event mEvents[MAX_EVENTS];

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

