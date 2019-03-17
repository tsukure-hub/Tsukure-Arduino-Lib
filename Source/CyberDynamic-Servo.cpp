/*

	CyberDynamic-Servo

*/

#include "Arduino.h"
#include "CyberDynamic-Servo.h"


CyberDynamic_Servo::CyberDynamic_Servo(bool isDebug, int thisServoPin)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_ServoPin = thisServoPin;
}


void CyberDynamic_Servo::Init()
{
	// Do Nothing
}