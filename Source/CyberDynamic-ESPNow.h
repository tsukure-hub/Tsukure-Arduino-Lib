/*

CyberDynamic-ESPNow - Library for Arduino ESPNow

*/


#ifndef CyberDynamic_ESPNow_h
#define CyberDynamic_ESPNow_h

#include "Arduino.h"

class CyberDynamic_ESPNow
{
  public:
    CyberDynamic_ESPNow(bool isDebug);
    CyberDynamic_ESPNow(bool isDebug, int thisWirelessChannel);
    void Init(void);
	
  private:
    bool _isDebug;

    int _WirelessChannel = 1;
};

#endif