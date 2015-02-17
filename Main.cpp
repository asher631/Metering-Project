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
#include "Instance.h"											//Provides an abstracted definition for a metering instance

//User defined modules
#include "Input/UserInput/UserInput.h"
#include "Input/Metering/Metering.h"
#include "Output/Screen/Screen.h"
#include "Output/LED/LED.h"

//Global Variables

const int PIN_INTERRUPT = 2				//The pin for the interrupt. This cannot change.
const int PIN_POWER = -1;				//Pin that is associated with the power button
const int PIN_START = -1;				//The pin that is associated with the start button
const int PIN_METERING_COM = -1;		//The pin that is associated with the metering circuit
const int PIN_LEDS[] = {-1, -1, -1};	//The pin array that is associated with the LEDs
const int PIN_SCREEN[] = {-1, -1, -1};	//The pin array that is associated with the screen

Instance currentInstance;	//The current instance object

//Setup function, used for initializing variables, setting, classes
void Setup() {
	//Specify which pins are to be used as input and output
	//Example: pinMode(ledPin, OUTPUT);      // sets the digital pin as output
	userIn(PIN_POWER, PIN_START);
	
	currentInstance.Begin();
}

//Main Loop
void loop() {
	currentInstance.Sleep();							//Sleep for the interval (30ms)
	currentInstance.PerformActions(currentSleepCycle);	//Perform relevant action
}

