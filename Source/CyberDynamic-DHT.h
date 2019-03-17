/*

CyberDynamic-DHT - Library for Arduino DHT

*/


#ifndef CyberDynamic_DHT_h
#define CyberDynamic_DHT_h

#include "Arduino.h"

#define DHT22 	22
#define DHT11 	11


class CyberDynamic_DHT
{
  public:
    CyberDynamic_DHT(bool isDebug, int thisDHTType);
    void Init(void);
	
  private:
    bool _isDebug;

    int _DHTType = DHT22;
};

#endif