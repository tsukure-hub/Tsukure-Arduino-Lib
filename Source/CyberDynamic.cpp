/*

	CyberDynamic

*/

#include "Arduino.h"
#include "CyberDynamic.h"

CyberDynamic::CyberDynamic(bool isDebug)
{
	// Set Debug Mode
	_isDebug = isDebug;
	
}

void CyberDynamic::BeginDebug()
{
	if (_isDebug)
	{
		Serial.begin(115200);
	}
}

void CyberDynamic::EndDebug()
{
	if (_isDebug)
	{
		Serial.end();
	}
}

void CyberDynamic::Debug(String thisText)
{
	if (_isDebug)
	{
		Serial.println(thisText);
	}
}

void CyberDynamic::SetDebugBaudRate(int thisBaudRate)
{
	Serial.end();
	Serial.begin(thisBaudRate);	
}