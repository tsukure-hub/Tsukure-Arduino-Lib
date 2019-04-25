/*

CyberDynamic-Display - Library for Arduino Displays

*/


#ifndef CyberDynamic_DCMotor_h
#define CyberDynamic_DCMotor_h

#include "Arduino.h"

#define DCMotor_FREE 0
#define DCMotor_FWD 1
#define DCMotor_BWD 2

class CyberDynamic_DCMotor
{
  public:
    CyberDynamic_DCMotor(bool isDebug, int thisFW1, int thisBW1, int thisSP1);
	void Loop(void);
	void SetDirection(int thisDirection);
	int GetDirection(void);
	void SetSpeed(int thisSpeed);
	
  private:
    bool _isDebug;
	
	// Button allocation
	
	int _FW1 = 0;
	int _BW1 = 0;

	int _SP1 = 0;
	
	int _Speed = 0;						// 0 - 255
	int _Direction = DCMotor_FREE;  	// 0 = Free; 1 = Right/Forward; 2 = Left/Backward; 
};

#endif