/*

CyberDynamic-MQTT - Library for Arduino MQTT

*/


#ifndef CyberDynamic_MQTT_h
#define CyberDynamic_MQTT_h

#include "Arduino.h"


class CyberDynamic_MQTT
{
  public:
    CyberDynamic_MQTT(bool isDebug, String thisMQTTHost);
    void Init(void);
	
  private:
    bool _isDebug;

    String _MQTTHost = "";
};

#endif