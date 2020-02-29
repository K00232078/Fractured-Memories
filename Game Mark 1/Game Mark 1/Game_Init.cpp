#include "Game.h"
/*
	Intialzes varaibles at begggining.
*/
bool Game::init()
{
	/* THIS CODE GRABS THE CURRENT RESOLUTION OF THE SCREEN */
	screenWidth = sf::VideoMode::getDesktopMode().width;
	screenHeight = sf::VideoMode::getDesktopMode().height;
	resolution.x = screenWidth;
	resolution.y = screenHeight;
	cout << screenWidth << ", " << screenHeight << endl;
	/* WE CAN USE THIS TO SET THE SIZE */

	//initialise all stuff that needs to be done before the game starts
	//Like Create a video mode object
	vm = new sf::VideoMode(screenWidth,screenHeight);
	textPopUp = Cooldown(300);
	//Like Create and open a window for the game
	window = new sf::RenderWindow(*vm, "", sf::Style::Default);
	//Init gamemenu text

	gameMenu->InitialiseText();
	guess = new Guess(clueManager, window, frameCount);
	//Sprite loading
	/*------------START OF SPRITE SETUP ---------------*/
	/*------------ Here you can use Set Positions, Origins, Initial Scale, and the Sprite itself ---------------*/
	/*------------ In future iterations we can farm this out to a level object. ---------------*/
	SetUpLevel();

	/*------------END OF INIT : Execute Loop ---------------*/
	GameLoop();
	return resetLevel;
} // End of initialisation