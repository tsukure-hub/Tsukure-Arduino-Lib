/*

CyberDynamic-WiFi - Library for Arduino WiFi

*/


#ifndef CyberDynamic_WiFi_h
#define CyberDynamic_WiFi_h

#include "Arduino.h"

class CyberDynamic_WiFi
{
  public:
    CyberDynamic_WiFi(bool isDebug);
    CyberDynamic_WiFi(bool isDebug, int thisWirelessChannel);
    void Init(void);
	
  private:
    bool _isDebug;

    int _WirelessChannel = 1;
};

#endif