/*

	CyberDynamic-LoRa

*/

#include "Arduino.h"
#include "CyberDynamic-LoRa.h"



CyberDynamic_LoRa::CyberDynamic_LoRa(bool isDebug)
{
	// Set Debug Mode
	_isDebug = isDebug;
}

CyberDynamic_LoRa::CyberDynamic_LoRa(bool isDebug, int thisLoRaChannel)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_LoRaChannel = thisLoRaChannel;
}


void CyberDynamic_LoRa::Init()
{
	// Do Nothing
}