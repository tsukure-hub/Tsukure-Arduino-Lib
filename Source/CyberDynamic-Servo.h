/*

CyberDynamic-Servo - Library for Arduino Servo

*/


#ifndef CyberDynamic_Servo_h
#define CyberDynamic_Servo_h

#include "Arduino.h"


class CyberDynamic_Servo
{
  public:
    CyberDynamic_Servo(bool isDebug, int thisServoPin);
    void Init(void);
	
  private:
    bool _isDebug;

    int _ServoPin = -1;
};

#endif