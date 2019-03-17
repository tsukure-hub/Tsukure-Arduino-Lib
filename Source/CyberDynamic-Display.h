/*

CyberDynamic-Display - Library for Arduino Displays

*/


#ifndef CyberDynamic_Display_h
#define CyberDynamic_Display_h

#include "Arduino.h"

#define SSD1306_128x64_SPI 	0 // SPI
#define SSD1306_128x32_SPI 	1 // SPI
#define ST7920_128x64_SPI 	2 // SPI
#define ST7920_128x32_SPI 	3 // SPI
#define LCDI2C_16x2_I2C 	4 // SDA, I2C

class CyberDynamic_Display
{
  public:
    CyberDynamic_Display(bool isDebug, int thisDisplayType);
	void InitDisplay(void);
	
  private:
    bool _isDebug;
	
	int _DisplayWidth = 0;
	int _DisplayHeight = 0;
};

#endif