#include <stdbool.h>
#include <inttypes.h>
#include <cmsis_os.h>
#include "stm32f4xx_hal.h"
#include "constant.h"
#include "fs/myspi.h"

const uint16_t pinClk = FS_GPIO_CLK_PIN;
const uint16_t pinMosi = FS_GPIO_MOSI_PIN;
const uint16_t pinMiso = FS_GPIO_MISO_PIN;

const int CMD_LS = 0x2;
const int CMD_CAT = 0x3;
const int CMD_INIT = 0x4;
const int CMD_NB_GROUPS = 0x5;
const int CMD_GET_GROUP = 0x6;
const int CMD_NB_PATTERNS      = 0x7;
const int CMD_GET_PATTERN_NAME = 0x8;
const int CMD_GET_PATTERN      = 0x9;

const uint8_t RET_ERR = 0x0;
const uint8_t RET_OK  = 0x1;

const int clkDelay = 1000;

inline static void digitalWrite(uint16_t gpioPin, uint8_t state)
{
	HAL_GPIO_WritePin(FS_GPIO_PORT, gpioPin, (GPIO_PinState)state);
}

inline static uint8_t digitalRead(uint16_t gpioPin)
{
	return HAL_GPIO_ReadPin(FS_GPIO_PORT, gpioPin);
}

static void delayMicroseconds(uint32_t i)
{
	i <<= 5;
	while(i--);
}


// set High clock
void sHClk()
{
	delayMicroseconds(clkDelay);
	digitalWrite(pinClk, 1);
	delayMicroseconds(clkDelay);
}

// set Low clock
void sLClk()
{
	delayMicroseconds(clkDelay);
	digitalWrite(pinClk, 0);
	delayMicroseconds(clkDelay);
}

int recv4()
{
	int data = 0;

	sLClk();
	for (int i=0; i<4;i++) {
		sHClk();
		int bit = digitalRead(pinMiso);
		data = (data << 1) | bit;
		sLClk();
	}
	return data;
}

uint8_t recv8()
{
	int h = recv4();
	int l = recv4();
	return (h<<4) | l;
}

void send4(int data)
{
	sLClk();
	for (int i=0; i<4;i++) {
		digitalWrite(pinMosi, (data & 0x8) );
		data <<= 1;

		sHClk();
		sLClk();
	}
}

void send8(int data)
{
	send4((data & 0xF0) >> 4);
	send4(data & 0x0F);
}

void recvString(char *buffer)
{
	int i=0;
	do {
		buffer[i] = recv8();
		i++;
	} while (buffer[i-1] != '\0');
}

void sendString(const char *buffer)
{
	int i=0;
	do {
		send8(buffer[i]);
		i++;
	} while(buffer[i-1]);
}

#define MAX_PATH 64
char buffer[MAX_PATH];
// List
char bufferList[MAX_PATH*4];
uint32_t _listI;

void CUB_MySPIInit()
{
	// init clk
	digitalWrite(pinClk, 0);

	uint8_t ret = RET_ERR;
	do {
		send4(CMD_INIT);
		osDelay(100);
		recv4();
	} while (ret == RET_ERR);
}

inline static void d()
{
	osDelay(1);
}

uint8_t CUB_MGetNbGroups()
{
	send4(CMD_NB_GROUPS);
	d();
	return recv8();
}

void CUB_MSelectGroup(uint8_t id, char *outName)
{
	send4(CMD_GET_GROUP);
	d();
	send8(id);
	d();
	recvString(outName);
	d();
}

uint8_t CUB_MGetNbPatterns()
{
	send4(CMD_NB_PATTERNS);
	d();
	return recv8();
}

void CUB_MGetPatternName(uint8_t id, char *outName)
{
	send4(CMD_GET_PATTERN_NAME);
	d();
	send8(id);
	d();
	recvString(outName);
}

void CUB_MGetPattern(uint8_t id, char *out)
{
	send4(CMD_GET_PATTERN);
	d();
	send8(id);
	d();
	recvString(out);
}


void CUB_FsList(const char *dirpath)
{
	send4(CMD_LS);
	sendString(dirpath);
	osDelay(100);
	recvString(bufferList);
	_listI = 0;
	osDelay(100);
}

/**
 * Get the next child name of the previous
 * listed directory.
 * out - will contain the file name
 * isDir - will indicates if it's a subdirectory
 * returns true if the output is valid or
 * false if there was no more child.
 */
bool CUB_FsNextChild(char *out, bool *isDir)
{
	bool go = true;
	bool ret = true;
	uint32_t i = 0;
	*isDir = false;
	do {
		out[i] = bufferList[_listI];
		if (out[i] == '\0') {
			go = false;
			if (i==0) ret = false;
		} else if (out[i] == '/') {
			*isDir = true;
			out[i] = '\0';
			go = false;
			_listI++;
			if (bufferList[_listI] == ':')
				_listI++;
		} else if (out[i] == ':') {
			out[i] = '\0';
			go = false;
			_listI++;
		} else {
			i++;
			_listI++;
		}
	} while (go);

	return ret;
}

void CUB_FsCat(const char *filepath, char *output)
{
	send4(CMD_CAT);
	sendString(filepath);
	osDelay(100);
	recvString(buffer);
	osDelay(100);
}


