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
		Sleep();
		bool rest(double milliseconds);
		bool hibernate(double milliseconds);
	private:
		
	
	
}