#include "Game.h"

void Game::EventKeyboard(sf::Event event)
{
	//not movement keys
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}

	if (stateManager.CURRENT_STATE == stateManager.HOW_TO_PLAY && Keyboard::isKeyPressed(Keyboard::BackSpace))
	{
		stateManager.CURRENT_STATE = stateManager.MENU;
	}

	//if (Keyboard::isKeyPressed(Keyboard::M))
	//{
	//	stateManager.CURRENT_STATE = stateManager.MENU;
	//}

	//if (Keyboard::isKeyPressed(Keyboard::P))
	//{
	//	stateManager.CURRENT_STATE = stateManager.PUZZLE;
	//}

	//For Testing
	//if (Keyboard::isKeyPressed(Keyboard::L))
	//{
	//	std::cout << "Button Pressed" << endl;
	//	gamePaused = !gamePaused;
	//	if (gamePaused)
	//	{
	//		stateManager.CURRENT_STATE = stateManager.PAUSE;
	//	}
	//	else
	//	{
	//		stateManager.CURRENT_STATE = stateManager.PLAY;
	//	}
	//	std::cout << "Game Paused: " << gamePaused << endl;
	//}

	if (Keyboard::isKeyPressed(Keyboard::T))
	{
		std::cout << "Current Position: " << player.m_position.x << ", " << player.m_position.y << endl;
	}
	/*
	if (Keyboard::isKeyPressed(Keyboard::K))
	{
		stateManager.CURRENT_STATE = stateManager.PLAY;
	}*/

	if (stateManager.STORY_STATE == stateManager.PICKUP_CLUE)
	{
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			readingText = false;
			stateManager.STORY_STATE = stateManager.NUll;
		}
	}

	/*if (Keyboard::isKeyPressed(Keyboard::Enter) && stateManager.CURRENT_STATE==stateManager.MENU && stateManager.STORY_STATE != 0)
	{
		stateManager.CURRENT_STATE = stateManager.PLAY;
	}
	*/
	if (Keyboard::isKeyPressed(Keyboard::Enter) && stateManager.STORY_STATE == 0)
	{
		storyEngine.state++;
		if (storyEngine.state >= storyEngine.openingScene.size())
		{
			storyEngine.state = 0;
			stateManager.STORY_STATE++;
			stateManager.CURRENT_STATE = stateManager.PLAY;
		}
	}

	if (stateManager.CURRENT_STATE == stateManager.PLAY || stateManager.CURRENT_STATE == stateManager.GUESS_KILLER)
	{
		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			viewingInventory = !viewingInventory;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		gameMenu->MoveDown();
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		gameMenu->MoveUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::B))
	{
		cout << "Mouse X: " << sf::Mouse::getPosition().x <<  endl;
		cout << "Mouse Y: " << sf::Mouse::getPosition().y <<  endl;
		
	}




	//Checks if the current state is MENU and if the player presses enter
	//If so depening on the value of seltectedItemIndex is currently
	//1 = play game, 2 = how to play screen & 3 = close program.
	if (stateManager.CURRENT_STATE == stateManager.MENU && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
			switch (gameMenu->selectedItemIndex)
			{
				case 0:
					stateManager.STORY_STATE = stateManager.OPENING_SCENE;
					break;
				case 1: 
					stateManager.CURRENT_STATE = stateManager.HOW_TO_PLAY;
					break;
				case 2:
					stateManager.STORY_STATE = stateManager.MENU_EXIT;
					break;
				default: 
					cout << "Invalid option" << endl;
					break;
			} //End of switch
	}

	/*
		If player presses left key in render menu then call moveLeft() to update selcted item
	*/
	if (Keyboard::isKeyPressed(Keyboard::Right) && stateManager.CURRENT_STATE == stateManager.GUESS_KILLER)
	{
		guess->moveLeft();
	}

	/*
		If player presses right key in render menu then call moveRight() to update selcted item
	*/
	if (Keyboard::isKeyPressed(Keyboard::Left) && stateManager.CURRENT_STATE == stateManager.GUESS_KILLER)
	{
		guess->moveRight();
	}

	/*
		Controls each time the player presses enter at the guess sytem.
		Increase guessSelectionState in order to go to teh next set of clues.
		Set answer to true after the third set in order to ask the player if they wish to 
		keep their answer.
	*/
	if (stateManager.CURRENT_STATE == stateManager.DEATH)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			cout << "enter pressed";
			resetLevel = true;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			resetLevel = false;
		}
	}

	if (stateManager.CURRENT_STATE == stateManager.GUESS_KILLER && guess->speechSaid)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{

			switch (guess->guessSelctionState)
			{
			case 0:
				guess->itemSelcted();
				guess->guessSelctionState = 1;
				guess->itemSelected = 0;
				break;
			case 1: guess->itemSelcted();
				guess->guessSelctionState = 2;
				guess->itemSelected = 0;
				break;
			case 2:
				guess->itemSelcted();
				guess->itemSelected = 0;
				guess->answer = true;
				break;
			case 3:
			default:
				break;
			}
		}
	}

	/*
		Keep text on screen when the player reaches the guess phase until they hit enter
	*/
	if (stateManager.CURRENT_STATE == stateManager.GUESS_KILLER)
	{
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			if (guess->speechSaid == false)
			{
				guess->speechSaid = true;
			}
		}
	}
}//End of GameEventKeyboard