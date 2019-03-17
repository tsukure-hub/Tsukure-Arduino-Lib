/*

	CyberDynamic-ESPNow

*/

#include "Arduino.h"
#include "CyberDynamic-ESPNow.h"



CyberDynamic_ESPNow::CyberDynamic_ESPNow(bool isDebug)
{
	// Set Debug Mode
	_isDebug = isDebug;
}

CyberDynamic_ESPNow::CyberDynamic_ESPNow(bool isDebug, int thisWirelessChannel)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_WirelessChannel = thisWirelessChannel;
}


void CyberDynamic_ESPNow::Init()
{
	// Do Nothing
}