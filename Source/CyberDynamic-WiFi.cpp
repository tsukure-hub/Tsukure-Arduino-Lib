/*

	CyberDynamic-WiFi

*/

#include "Arduino.h"
#include "CyberDynamic-WiFi.h"



CyberDynamic_WiFi::CyberDynamic_WiFi(bool isDebug)
{
	// Set Debug Mode
	_isDebug = isDebug;
}

CyberDynamic_WiFi::CyberDynamic_WiFi(bool isDebug, int thisWirelessChannel)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_WirelessChannel = thisWirelessChannel;
}


void CyberDynamic_WiFi::Init()
{
	// Do Nothing
}