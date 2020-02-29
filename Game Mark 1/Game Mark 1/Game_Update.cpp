/*
** Last Author: Thomas
** Date Modified: 29/11/19
** Version: 0.001
** Change Log:
*** -------- <29/11/19>
***	<Thomas> Added Signiature Head
***	<Thomas> Pulled Update into a Seperate file.
*** --------- End of Changes
*/

#include "Game.h"

void Game::Update()
{
	
	window->clear(sf::Color::White);
	switch (stateManager.CURRENT_STATE)
	{
		case 0:
			//menu
			renderMenu();
			break;
		case 1:
			//play
			renderPlay();
		move();
			break;
		case 2:
			//puzzle
			renderPuzzle();
			break;
		case 3:
			//pause
			window->clear(sf::Color::Black);
			//renderPaused()
			window->display();
			break;
		case 4: 	
			//How to play screen
			gameMenu->HowToPlay(window);
			break;
		case 5:
			//nextLevel
			window->clear(sf::Color::Black);
			
			NextLevel();

			window->display();
			break;
		case 6:
		//	window->clear(sf::Color::Red);
			GuessSpeech();
			break;
		case 8: //death scene
			window->clear(sf::Color::Black);
			if (died)
			{
				endScene.calculateLocations();
				endScene.DrawEnd(win, window);
			}
			window->display();
			break;
		default:
			window->clear(sf::Color::Magenta);
			break;
	}
	//render();
//	move();
}
