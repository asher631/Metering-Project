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

 //Libraries to include
 #include <Input/Metering/ADE7753.h>							//ADE7753 communication library
 #include <Output/Screen/Adafruit-GFX-library/Adafruit_GFX.h>	//Library that the sharp memory library extends
 #include <Output/Screen/SharpMemoryLCD/SharpMemoryLcd.h>		//Sharp Memory LCD communication library
 #include <PowerSaving/RocketScreamLibrary/LowPower/h>			//Provides powerful low-power sleep functions
 
 //User defined modules
 #include "Input/UserInput/UserInput.h"
 #include "Input/Metering/Metering.h"
 #include "Output/Screen/Screen.h"
 #include "Output/LED/LED.h"
 
//Main Loop
void loop() {
	double currentTime;				//The current time in milliseconds

	sleep();						//Sleep for the interval
	performActions(currentTime);	//Perform relevant actions
	
}

//The function we will go to when we want to sleep,
//Will return true if there weren't any errors during the sleep cycle
//Will return false if there was an error generated during the sleep cycle
bool sleep(){

	return true;
}

//The function we will go to when we are awake and we want to perform out actions
//before we go back to sleep.
bool performActions(double currentTime){
	
	//Logic here that will determine which actions to perform based on the value of the current time
	//Actions to perform:
	//Check for user input
	//Poll IC if running
	//Talk to LEDs
	//Talk to screen

	return true;
}


