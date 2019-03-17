/*

	CyberDynamic-DHT

*/

#include "Arduino.h"
#include "CyberDynamic-DHT.h"


CyberDynamic_DHT::CyberDynamic_DHT(bool isDebug, int thisDHTType)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_DHTType = thisDHTType;
}


void CyberDynamic_DHT::Init()
{
	// Do Nothing
}