/*

	CyberDynamic-Display-Nextion

*/

#include "Arduino.h"
#include "Nextion.h"
#include "CyberDynamic-Display-Nextion.h"



CyberDynamic_Display_Nextion::CyberDynamic_Display_Nextion(bool isDebug, int thisDisplayType)
{
	// Set Debug Mode
	_isDebug = isDebug;
	
}

void CyberDynamic_Display_Nextion::InitDisplay()
{
	nexInit();
}
void CyberDynamic_Display_Nextion::Display()
{
	//nexLoop(nex_listen_list);
}