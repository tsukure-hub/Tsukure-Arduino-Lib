/*

	CyberDynamic-IR

*/

#include "Arduino.h"
#include "CyberDynamic-IR.h"


CyberDynamic_IR::CyberDynamic_IR(bool isDebug, int thisTXPin)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_TXPin = thisTXPin;
}


CyberDynamic_IR::CyberDynamic_IR(bool isDebug, int thisTXPin, int thisRXPin)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_TXPin = thisTXPin;
	_RXPin = thisRXPin;
}


void CyberDynamic_IR::Init()
{
	// Do Nothing
}