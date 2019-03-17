/*

CyberDynamic-IR - Library for Arduino IR

*/


#ifndef CyberDynamic_IR_h
#define CyberDynamic_IR_h

#include "Arduino.h"

class CyberDynamic_IR
{
  public:
    CyberDynamic_IR(bool isDebug, int thisTXPin);
    CyberDynamic_IR(bool isDebug, int thisTXPin, int thisRXPin);
    void Init(void);
	
  private:
    bool _isDebug;

    int _TXPin = -1;
    int _RXPin = -1;
};

#endif