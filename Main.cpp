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

//Libraries to include
#include "Input/Metering/ADE7753.h"							//ADE7753 communication library
#include "Output/Screen/Adafruit-GFX-library/Adafruit_GFX.h"	//Library that the sharp memory library extends
#include "Output/Screen/SharpMemoryLCD/SharpMemoryLcd.h"		//Sharp Memory LCD communication library
#include "PowerSaving/RocketScreamLibrary/LowPower/h"			//Provides powerful low-power sleep functions

//User defined modules
#include "Input/UserInput/UserInput.h"
#include "Input/Metering/Metering.h"
#include "Output/Screen/Screen.h"
#include "Output/LED/LED.h"

//Global Variables
const int readUserInputInterval = 5;		//Check every 5 sleep cycles
const int readkMeteringInputInterval = 3;	//Check every 3 sleep cycles
const int talkLEDInterval = 2;				//Talk to them every 2 sleep cycles
const int talkScreenInterval = 2;			//Talk to it every 2 sleep cycles

const int PIN_POWER = -1;
const int PIN_START = -1;
const int PIN_METERING_COM = -1;
const int PIN_LEDS[] = {-1, -1, -1};

double currentTime;			//The current time in milliseconds
double currentSleepCycle;	//The current sleep cycle we are on.

Sleep sleeper;				//The sleep object, will be used to perform rest operations
UserInput userIn;			//The user input object, will be used to evaluate any input from the user

//Setup function, used for initializing variables, setting, classes
void Setup() {
	currentTime = 0;
	currentSleepCycle = 0;
	
	userIn(PIN_POWER, PIN_START);
	//Specify which pins are to be used as input and output
	//Example: pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

//Main Loop
void loop() {

	Sleep();							//Sleep for the interval
	PerformActions(currentSleepCycle);	//Perform relevant actions

}

//The function we will go to when we want to sleep,
//Will return true if there weren't any errors during the sleep cycle
//Will return false if there was an error generated during the sleep cycle
//Increments currentSleepCycle after a rest
bool Sleep(){

	sleeper.Rest();
	currentSleepCycle ++;
	return true;
}

//The function we will go to when we are awake and we want to perform out actions
//before we go back to sleep.
bool PerformActions(double sleepCycle){
	//Logic here that will determine which actions to perform based on the value of the current time
	//Actions to perform:
	//Check for user input
	//Poll IC if running
	//Talk to LEDs
	//Talk to screen
	
	if(sleepCycle % readUserInputInterval == 0){
		//Read user input, such as restart, start, timer, etc.
	}
	if(sleepCycle % readkMeteringInputInterval == 0) {
		//Read metering input
	}
	if(sleepCycle % talkLEDInterval == 0) {
		//Display the current power being produced to the LEDs
	}
	if(sleepCycle % talkScreenInterval == 0) {
		//Print the new screen on the memory LCD
	}

	return true;
}


