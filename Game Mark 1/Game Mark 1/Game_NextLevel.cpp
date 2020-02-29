#include "Game.h"

/*
	Run whenever their is a new level
*/
void Game::NextLevel()
{
	
	levelManager.ChangeLevel();
	SetUpLevel();
	inventoryViewer->InitialisePositions();
	stateManager.CURRENT_STATE = stateManager.PLAY;
}