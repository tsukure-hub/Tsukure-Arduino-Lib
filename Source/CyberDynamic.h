/*

CyberDynamic - Library for Arduino

*/

#ifndef CyberDynamic_h
#define CyberDynamic_h

#include "Arduino.h"

class CyberDynamic
{
  public:
    CyberDynamic(bool isDebug);
    void BeginDebug(void);						// Begin Serial Comms for Debug
    void EndDebug(void);						// End Serial Comms for Debug
    void Debug(String thisText);				// Print to Serial Comms for Debug
    void SetDebugBaudRate(int thisBaudRate);	// Change Serial Comms Speed
	
  private:
    bool _isDebug;
};

#endif