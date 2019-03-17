/*

	CyberDynamic-MySQL

*/

#include "Arduino.h"
#include "CyberDynamic-MySQL.h"



CyberDynamic_MySQL::CyberDynamic_MySQL(bool isDebug, String thisHost)
{
	// Set Debug Mode
	_isDebug = isDebug;

	// Set Channel
	_Host = thisHost;
}


void CyberDynamic_MySQL::Init()
{
	// Do Nothing
}