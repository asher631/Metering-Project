/*
* Title: Screen.cpp
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Library definition for interfacing with the screen that we will use. Currently, this is the 
* Sharp Memory LCD 2.7in.
* 
* This library has a very few key functions:
* 1) Write something to the screen
* 2) Clear the screen
* 3) Flash the screen
*/

Screen::Screen() {
	//This is the constructor, here we need to initialize any constants or settings
	flashDelay = 50;	//Set delay time between inversions when flashing the screen
	
	screenObject.LcdInitialize();	//Initialize the screen
	screenObject.LcdClearBuffer();	//Clear the buffer of the screen
}

bool Screen::Write(char message[]) {
	//This is the function that will accept a message in the form of a character array and will write it to the screen
	
	for(int count = 0; count < sizeof(message) - 1; count ++) {
		screenObject.write(message[count]);
	}
	
	return true;
}

bool Screen::Clear() {
	//Clear the screen
	screenObject.LcdPrintImage(void);
	return true;
}

bool Screen::Flash() {
	//Flashes the screen quickly
	screenObject.invert(flashDelay);	
	return true;
}