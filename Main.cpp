/*
* Title: Main.cpp
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Hub of the program. Where everything comes together.
*
*/

//Arduino provided libraries
#include "Arduino.h"

//Libraries from third parties to include
#include "Input/Metering/ADE7753.h"								//ADE7753 communication library
#include "Output/Screen/Adafruit-GFX-library/Adafruit_GFX.h"	//Library that the sharp memory library extends
#include "Output/Screen/SharpMemoryLCD/SharpMemoryLcd.h"		//Sharp Memory LCD communication library
#include "PowerSaving/RocketScreamLibrary/LowPower/h"			//Provides powerful low-power sleep functions

//User defined modules
#include "Instance.h"											//Provides an abstracted definition for a metering instance

//Global Variables
Instance currentInstance;	//The current instance object

void Setup() {
	//Setup function, used for initializing variables, setting, classes
	currentInstance.Begin();
}

void loop() {
	//Main Loop
	currentInstance.Sleep();							//Sleep for the interval (30ms)
	currentInstance.PerformActions(currentSleepCycle);	//Perform relevant action
}

