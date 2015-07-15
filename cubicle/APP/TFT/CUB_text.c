/**
 * Port of Liquid Cristal library
 * from Arduino ressources.
 * Supports only 4 bits mode.
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "stm32f4xx_hal.h"
#include "CUB_text.h"

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set:
//    DL = 1; 8-bit interface data
//    N = 0; 1-line display
//    F = 0; 5x8 dot character font
// 3. Display on/off control:
//    D = 0; Display off
//    C = 0; Cursor off
//    B = 0; Blinking off
// 4. Entry mode set:
//    I/D = 1; Increment by 1
//    S = 0; No shift
//

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define LOW GPIO_PIN_RESET
#define HIGH GPIO_PIN_SET

void CUB_TextInit(uint8_t nbRows, uint8_t nbColumns);
void CUB_TextClear();
void CUB_TextHome();
void CUB_TextPrint(const char *str);
void CUB_TextWrite(const char);
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

// Private
static void command(uint8_t);
static void send(uint8_t, uint8_t);
static void write4bits(uint8_t);
static void pulseEnable();
static void _write(uint8_t);

static uint16_t _data_pins[4];
static uint8_t _displayfunction;
static uint8_t _displaycontrol;
static uint8_t _displaymode;
static uint8_t _numlines;
static uint8_t _currline;

static void delayMicroseconds(uint32_t i)
{
	i <<= 5;
	while(i--);
}

inline static void digitalWrite(uint16_t gpioPin, uint8_t state)
{
	HAL_GPIO_WritePin(LCD_GPIO_PORT, gpioPin, (GPIO_PinState)state);
}

void CUB_TextPrint(const char *str)
{
	while (*str)
		_write(*str++);
}

void CUB_TextInit(uint8_t nbRows, uint8_t nbColumns)
{
	_data_pins[0] = LCD_PIN_D4;
	_data_pins[1] = LCD_PIN_D5;
	_data_pins[2] = LCD_PIN_D6;
	_data_pins[3] = LCD_PIN_D7;

  	_displayfunction = LCD_2LINE | LCD_5x8DOTS;

  	_numlines = nbRows;
  	_currline = 0;

  	// for some 1 line displays you can select a 10 pixel high font
  	//if ((dotsize != 0) && (lines == 1)) {
  	//  _displayfunction |= LCD_5x10DOTS;
  	//}

  	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
  	// according to datasheet, we need at least 40ms after power rises above 2.7V
  	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
  	delayMicroseconds(50000);
  	// Now we pull both RS and R/W low to begin commands
  	digitalWrite(LCD_PIN_RS, LOW);
  	digitalWrite(LCD_PIN_EN, LOW);

  	//put the LCD into 4 bit
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46

    // we start in 8bit mode, try to set 4 bit mode
    write4bits(0x03);
    delayMicroseconds(4500); // wait min 4.1ms

    // second try
    write4bits(0x03);
    delayMicroseconds(4500); // wait min 4.1ms

    // third go!
    write4bits(0x03);
    delayMicroseconds(150);

    // finally, set to 8-bit interface
    write4bits(0x02);

  	// finally, set # lines, font size, etc.
  	command(LCD_FUNCTIONSET | _displayfunction);  

  	// turn the display on with no cursor or blinking default
  	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
  	CUB_TextDisplay();

  	// clear it off
  	CUB_TextClear();

  	// Initialize to default text direction (for romance languages)
  	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
  	// set the entry mode
  	command(LCD_ENTRYMODESET | _displaymode);

}

/********** high level commands, for the user! */
void CUB_TextClear()
{
  	command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
  	delayMicroseconds(2000);  // this command takes a long time!
}

void CUB_TextHome()
{
  	command(LCD_RETURNHOME);  // set cursor position to zero
  	delayMicroseconds(2000);  // this command takes a long time!
}

void CUB_TextSetCursor(uint8_t col, uint8_t row)
{
  	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
  	if ( row > _numlines ) {
    	row = _numlines-1;    // we count rows starting w/0
  	}

  	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void CUB_TextNoDisplay()
{
  	_displaycontrol &= ~LCD_DISPLAYON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void CUB_TextDisplay()
{
  	_displaycontrol |= LCD_DISPLAYON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void CUB_TextNoCursor()
{
  	_displaycontrol &= ~LCD_CURSORON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void CUB_TextCursor()
{
  	_displaycontrol |= LCD_CURSORON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void CUB_TextNoBlink()
{
  	_displaycontrol &= ~LCD_BLINKON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void CUB_TextBlink()
{
  	_displaycontrol |= LCD_BLINKON;
  	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void CUB_TextScrollDisplayLeft()
{
  	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

void CUB_TextScrollDisplayRight()
{
  	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void CUB_TextLeftToRight()
{
  	_displaymode |= LCD_ENTRYLEFT;
  	command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void CUB_TextRightToLeft()
{
  	_displaymode &= ~LCD_ENTRYLEFT;
  	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void CUB_TextAutoscroll()
{
  	_displaymode |= LCD_ENTRYSHIFTINCREMENT;
  	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void CUB_TextNoAutoscroll()
{
  	_displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  	command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void CUB_TextCreateChar(uint8_t location, uint8_t charmap[])
{
  	location &= 0x7; // we only have 8 locations 0-7
  	command(LCD_SETCGRAMADDR | (location << 3));
  	for (int i=0; i<8; i++) {
    	_write(charmap[i]);
  	}
}

void CUB_TextQuit()
{
}

void CUB_TextWrite(const char c)
{
    _write(c);
}

void inverse2(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void CUB_TextPrintRight(char* str, uint32_t line)
{
	CUB_TextRightToLeft();
	inverse2(str);
	CUB_TextSetCursor(19, line);
	CUB_TextPrint(str);
	CUB_TextLeftToRight();
	inverse2(str);
}

void my_itoa2(int value, char str[]) 
{
	int i = 0;
	if (value >= 0) {
		do {
			str[i++] = value % 10 + '0';
		} while ((value /= 10) > 0);
		str[i] = '\0';
		inverse2(str);
	} else {
		strcpy(str,"");
	}
}

void CUB_TextPrintf(char *str, ...)
{
    va_list vl;
    va_start(vl, str);
    while(*str)
    {
        switch(*str){
        case '\n':
            CUB_TextSetCursor(0,1);
            CUB_TextPrint("                    ");
            CUB_TextSetCursor(0,1);
            break;
        case '%':
            str++;
            switch(*str){
            case 'i':
				{
					int i = va_arg(vl, int);
                    char c[2];
                    my_itoa2(i,c);
                    CUB_TextPrint(c);
                    break;
                }
            case 's':
			{
				char *str = va_arg(vl, char*);
                CUB_TextPrint(str);
                break;
            }
			case '.':
			{
				str++;
				switch(*str){
					case '*':
					{
						str++;
						switch(*str){
							case 's':
							{
								int i = va_arg(vl, int);
								char *str = va_arg(vl, char*);
								for (int j=0; j<i; j++) 
									_write(*(str+j));
								break;
							}
							default:
								CUB_TextPrint(".*");
						}
						break;
					}
					default:;
				}
				break;
			}
            default:
				_write('%');
            }
            break;
        default:
            _write(*str);
        }
        str++;
    }
    va_end(vl);
}

/*********** mid level commands, for sending data/cmds */

inline static void command(uint8_t value)
{
  	send(value, LOW);
}

inline static void _write(uint8_t value)
{
  	send(value, HIGH);
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void send(uint8_t value, uint8_t mode)
{
  	digitalWrite(LCD_PIN_RS, mode);

    write4bits(value>>4);
    write4bits(value);
}

void pulseEnable()
{
  	digitalWrite(LCD_PIN_EN, LOW);
  	delayMicroseconds(1);    
  	digitalWrite(LCD_PIN_EN, HIGH);
  	delayMicroseconds(1);    // enable pulse must be >450ns
  	digitalWrite(LCD_PIN_EN, LOW);
  	delayMicroseconds(100);   // commands need > 37us to settle
}

void write4bits(uint8_t value)
{
  	for (int i = 0; i < 4; i++) {
    	digitalWrite(_data_pins[i], (value >> i) & 0x01);
  	}

  	pulseEnable();
}

