/*

	CyberDynamic-MQTT

*/

#include "Arduino.h"
#include "CyberDynamic-MQTT.h"


CyberDynamic_MQTT::CyberDynamic_MQTT(bool isDebug, String thisMQTTHost)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_MQTTHost = thisMQTTHost;
}


void CyberDynamic_MQTT::Init()
{
	// Do Nothing
}