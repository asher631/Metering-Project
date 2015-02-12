/*
	CLass definitions of the sleep library. Function List:
	Constructor: 	Initializes any settings
	Rest: 			A short, 15ms power down
	Hibernate:		Power down until a wake signal comes in.
	TurnDown:		Turn off all non essential features of the chip.
	TurnUp:			Turn on all features of the chip, reset to default.
*/

#include "Sleep.h"

Sleep::Sleep(){
	//Initialize anything in the low-power library that we need. Define
	//any constants that need to be defined.
}

Sleep::Rest()
{
	//This will put the module into a power saving mode for a short period of time.
	//Since the low power library only specifies certain amounts of time to rest the module,
	//we will initially attempt to work around that.
	
	
}

Sleep::Hibernate(){
}
