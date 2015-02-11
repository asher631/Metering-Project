/*
Main Module

This module is where out program will start and where all other modules and functions
are called. It will contain the main loop and will link to the other modules.
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
 #include "Output/LEDs/LED.h"
 
//Main Loop
void loop() {
	int millisecondsToSleep = 1000;
	
	
	sleep(millsecondsToSleep);		//Sleep for the interval
	performActions();
}

//The function we will go to when we want to sleep,
//Will return true if there weren't any errors during the sleep cycle
//Will return false if there was an error generated during the sleep cycle
bool sleep(int milliseconds){

	return true;
}

//The function we will go to when we are awake and we want to perform out actions
//before we go back to sleep.
bool performActions(){
	
	return true;
}


