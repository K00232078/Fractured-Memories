#include "Game.h"

void Game::GuessSpeech()
{
	window->draw(*spriteManager->GetSprite("Textures/backgroundGuess.png")); //just a direct pointer reference to assure we arent duplicating this in memory.
	if (guess->speechSaid == false)
	{
		guess->LevelSpeech();
	}
	Guessevent();
}

void Game::Guessevent()
{	
	//Initialize
	guess->init();
	guess->checkState();
	guess->setupGuessWindow();

	if (stateManager.CURRENT_STATE == stateManager.GUESS_KILLER)
	{
		guess->DrawSelectedItems();
 		if (guess->answer)
		{
			guess->confirmAnswer(stateManager);
		}

		if (guess->GuessCompleted)
		{
			guess->GuessCompleted = false;
			guess->ResetClueScale();
			NextLevel();
		}
		/*
			Player fails to guess enemy
		*/
		if (guess->death)
		{
			stateManager.CURRENT_STATE = stateManager.DEATH;
			died = true;
		}
		/*
			Player gusses right.
		*/
		if (guess->RightGuess)
		{
			stateManager.CURRENT_STATE = stateManager.DEATH;
			died = true;
			win = true;
		}
	}

	/*
		Displays inventory if player presses I
	*/
	if (viewingInventory)
	{
		inventoryViewer->Draw(window);
	}
	
	window->display();
}