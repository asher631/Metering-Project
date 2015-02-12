/*
	This library will rap the lower power library to provide less options for
	our current program. Many of the functions are presented to the user will
	be simplified and only the features that we need will be wrapped.
*/

//Prevents issues with accidental double linking
#ifndef Sleep_h
#define Sleep_h

#include "RocketScreamLibrary/LowPower.h"

class Sleep
{
	public:
		Sleep(double );		//Initialize the Sleep object
		bool Rest();		//Sleep for a short amount of time, specifies the sleep cycle
		bool Hibernate();	//Deep sleep until an input wakes it up
	private:
		
	
	
}