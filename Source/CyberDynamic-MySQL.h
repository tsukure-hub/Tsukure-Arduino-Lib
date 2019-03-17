/*

CyberDynamic-MySQL - Library for Arduino MySQL

*/


#ifndef CyberDynamic_MySQL_h
#define CyberDynamic_MySQL_h

#include "Arduino.h"

class CyberDynamic_MySQL
{
  public:
    CyberDynamic_MySQL(bool isDebug, String thisHost);
    void Init(void);
	
  private:
    bool _isDebug;

    String _Host = "";
};

#endif