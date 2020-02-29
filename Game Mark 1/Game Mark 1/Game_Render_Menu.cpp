#include "Game.h"

/*
	Displays main menu and sub menus.
*/
void Game::renderMenu()
{
	
	window->clear(sf::Color::Black);

	//Draws menu to the screen when the game is run
	if (stateManager.CURRENT_STATE == stateManager.MENU)
	{
		window->draw(*spriteManager->GetSprite("Textures/menuBackground.png"));//Main menu background
		gameMenu->draw(window, window->getSize().x, window->getSize().y);
	}

	//If the player has pressed enter on the main menu
	if (stateManager.STORY_STATE == stateManager.OPENING_SCENE)
	{
		textManager->Render(window, frameCount, storyEngine.openingScene.at(storyEngine.state));
	}


	//Closes game when the player presses enter on 'exit' option.
	if (stateManager.STORY_STATE == stateManager.MENU_EXIT)
	{
		window->close();
	}

	//Shows game when the player presses enter on 'exit' option.
	else if (stateManager.CURRENT_STATE == stateManager.HOW_TO_PLAY)
	{
		gameMenu->HowToPlay(window);
	//	stateManager.CURRENT_STATE = stateManager.NUll;
	}
	window->display();
}