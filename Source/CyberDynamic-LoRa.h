/*

CyberDynamic-LoRa - Library for Arduino LoRa

*/


#ifndef CyberDynamic_LoRa_h
#define CyberDynamic_LoRa_h

#include "Arduino.h"

class CyberDynamic_LoRa
{
  public:
    CyberDynamic_LoRa(bool isDebug);
    CyberDynamic_LoRa(bool isDebug, int thisLoRaChannel);
    void Init(void);
	
  private:
    bool _isDebug;

    int _LoRaChannel = 1;
};

#endif