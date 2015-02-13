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
const int readUserInputInterval = 3;		//Check every 5 sleep cycles
const int readkMeteringInputInterval = 2;	//Check every 3 sleep cycles
const int talkLEDInterval = 1;				//Talk to them every 2 sleep cycles
const int talkScreenInterval = 1;			//Talk to it every 2 sleep cycles

const int PIN_INTERRUPT = 2				//The pin for the interrupt. This cannot change.
const int PIN_POWER = -1;				//Pin that is associated with the power button
const int PIN_START = -1;				//The pin that is associated with the start button
const int PIN_METERING_COM = -1;		//The pin that is associated with the metering circuit
const int PIN_LEDS[] = {-1, -1, -1};	//The pin array that is associated with the LEDs
cost int PIN_SCREEN[] = {-1, -1, -1};	//The pin array that is associated with the screen

double currentTime;			//The current time in milliseconds
double currentSleepCycle;	//The current sleep cycle we are on.

Sleep sleeper;				//The sleep object, will be used to perform rest operations
UserInput userIn;			//The user input object, will be used to evaluate any input from the user
MeterInput meterIn;			//The meter input object, will be used to read from the metering circuit

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

	Sleep();							//Sleep for the interval (30ms)
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
	double meterReading 0;
	
	if(sleepCycle % readUserInputInterval == 0){
		//Read user input, such as restart, start, timer, etc.
		HandleButtonPresses();
	}
	if(sleepCycle % readkMeteringInputInterval == 0) {
		//Read metering input
		meterReading = ReadInstantaneousPowerFromMeter();
	}
	if(sleepCycle % talkLEDInterval == 0) {
		//Display the current power being produced to the LEDs
	}
	if(sleepCycle % talkScreenInterval == 0) {
		//Print the new screen on the memory LCD
	}

	return true;
}

//This function will take the 
bool HandleButtonPresses() {
	bool powerButtonPressed = false;
	bool restartButtonPressed = false;
	
	powerButtonPressed = userIn.CheckPowerButton();
	restartButtonPressed = userIn.CheckRestartButton();
	
	if(powerButtonPressed && !restartButtonPressed) {
		//Then we need to go into shutdown mode
		sleeper.Hibernate();
	}
	else if(restartButtonPressed && !powerButtonPressed) {
		//Then we need to restart the state of the machine
		
	}
}

//This function will read the result from the meter
double ReadInstantaneousPowerFromMeter(){
	return meterIn.ReadInstantaneousPower();
}

bool StartNewInstance() {
	//This function will clear the state of the machine, such as time, sleep cycle,
	//clear the screen and reset the timer, and clear the cache on the metering circuit,
	//perhaps even flash the LEDs to indicate that there is a new state.
	
	currentTime = 0;
	currentSleepCycle = 0;
	
}

