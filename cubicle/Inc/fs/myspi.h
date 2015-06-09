#ifndef _MYSPI_H_
#define _MYSPI_H_

#include <inttypes.h>

void CUB_MySPIInit();


uint8_t CUB_MGetNbGroups();

void CUB_MSelectGroup(uint8_t id, char *outName);

uint8_t CUB_MGetNbPatterns();

void CUB_MGetPatternName(uint8_t id, char *outName);
void CUB_MGetPattern(uint8_t id, char *out);


#endif
