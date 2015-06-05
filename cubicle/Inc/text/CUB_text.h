#ifndef _CUB_TEXT_H_
#define _CUB_TEXT_H_

/**
 * Pin configuration.
 * You must program GPIO Output mode yourself
 */

#define LCD_GPIO_PORT GPIOD

#define LCD_PIN_EN GPIO_PIN_9
#define LCD_PIN_RS GPIO_PIN_8
#define LCD_PIN_D4 GPIO_PIN_10
#define LCD_PIN_D5 GPIO_PIN_11
#define LCD_PIN_D6 GPIO_PIN_12
#define LCD_PIN_D7 GPIO_PIN_13
// end of config

#include <inttypes.h>
#include <stdarg.h>

void CUB_TextInit(uint8_t nbRows, uint8_t nbColumns);
void CUB_TextClear();
void CUB_TextHome();
void CUB_TextPrint(const char *str);
void CUB_TextPrintf(char* format, ...);
void CUB_TextWrite(const char c);
void CUB_TextDisplay();
void CUB_TextNoDisplay();
void CUB_TextCursor();
void CUB_TextNoCursor();
void CUB_TextBlink();
void CUB_TextNoBlink();
void CUB_TextScrollDisplayLeft();
void CUB_TextScrollDisplayRight();
void CUB_TextLeftToRight();
void CUB_TextRightToLeft();
void CUB_TextAutoscroll();
void CUB_TextNoAutoscroll();
void CUB_TextCreateChar(uint8_t location, uint8_t charmap[]);
void CUB_TextSetCursor(uint8_t col, uint8_t row);
void CUB_TextQuit();

void my_itoa2(int value, char str[]);

#endif
