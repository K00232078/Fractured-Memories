#include "Game.h"

void Game::SetUpLevel()
{
	SpriteSetup();
	AddEnemies();
	AddPowerUp();
	AddClues();
}