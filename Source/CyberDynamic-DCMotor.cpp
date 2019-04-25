/*

	CyberDynamic-DCMotor

*/

#include "Arduino.h"
#include "CyberDynamic-DCMotor.h"



CyberDynamic_DCMotor::CyberDynamic_DCMotor(bool isDebug, int thisFW1, int thisBW1, int thisSP1)
{
	// Set Debug Mode
	_isDebug = isDebug;
	
	// Set Btn Pin Allocation
	
	_FW1 = thisFW1;
	_BW1 = thisBW1;
	_SP1 = thisSP1;
	
	// Set Pins
	
	 pinMode(_FW1, OUTPUT);
	 pinMode(_BW1, OUTPUT);
	 pinMode(_SP1, OUTPUT);
	
}


void CyberDynamic_DCMotor::Loop()
{
	switch (_Direction)
	{
		case DCMotor_BWD:	// BWD
			
			digitalWrite(_FW1, LOW);
			digitalWrite(_BW1, HIGH);

			analogWrite(_SP1, _Speed);

			break;

		case DCMotor_FWD:	// FWD
			
			digitalWrite(_FW1, HIGH);
			digitalWrite(_BW1, LOW);

			analogWrite(_SP1, _Speed);
			
			break;

		default:			// Free
			digitalWrite(_BW1, LOW);
			digitalWrite(_FW1, LOW);

			digitalWrite(_SP1, LOW);    
			break;
	}	
	
	
}

void CyberDynamic_DCMotor::SetDirection(int thisDirection)
{
	_Direction = thisDirection;
}


int CyberDynamic_DCMotor::GetDirection()
{
	return _Direction;
}

void CyberDynamic_DCMotor::SetSpeed(int thisSpeed)
{
	_Speed = thisSpeed;
}