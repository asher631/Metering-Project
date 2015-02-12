/*
* Title: Sleep.cpp
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Description: This is a class definition of the Sleep library that will have two core functions: 
* 1) Rest - a short (15ms) power down that attempt to conserve power in between times when the 
*      processor needs to be computing
* 2) Hibernate - An indefinite rest that will only be awaken from with an awake signal.
*
* The library includes two other functions, TurnUp and TurnDown that allow the user to specify
* if the chip should turn on or off the non essential features (like the ADC).
*/

#include "Sleep.h"

Sleep::Sleep() {
	//Initialize anything in the low-power library that we need. Define
	//any constants that need to be defined.
}

Sleep::Rest() {
	//This will put the module into a power saving mode for a short period of time.
	//Since the low power library only specifies certain amounts of time to rest the module,
	//we will initially attempt to work around that.
	
}

Sleep::Hibernate(){
	//This will place the chip into a deep power saving mode for an indefinite period of time.
	//The chip will only awaken upon an external signal.
	
}

Sleep::TurnDown() {
	//This function will disable everything that is non essential to the features of product
	//on the chip
}

Sleep::TurnUp() {
	//This function will enable everything to the factory standards on the chip.
}


