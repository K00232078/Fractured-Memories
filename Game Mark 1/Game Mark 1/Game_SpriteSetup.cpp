#include "Game.h"

void Game::SpriteSetup()
{
	/* If we keep the maze wall sprite exactly the same dimensions every time, we only need the one background
	** Origins should remain exactly the same, and positions too. 
	*/


	//Maze Background
	background = spriteManager->GetSprite("Textures/Background2.png");
	background->setOrigin(2329, 2329);
	background->setPosition(539, 539);

	//Maze Wall
	cout << "Current Level: " << levelManager.currentLevel << endl;
	maze->Setup(levelManager.currentLevel);
	maze->currentMazeSprite->setOrigin(539, 539);
	maze->currentMazeSprite->setPosition(0, 0);

	//Player loading
	//player.characterSprite = spriteManager->GetSprite("Textures/player.png");
	player.characterSprite->setOrigin(640, 360);
	player.collisionSprite->setOrigin(640, 360);
	
	if (firstLoad)
	{//we don't want to do this every time we load a level
		clue = spriteManager->GetSprite("Textures/gem2.png");
		clue->setOrigin(290.5, 293);
		clue->scale(0.1, 0.1);
		player.characterSprite->scale(0.2, 0.2);
		player.collisionSprite->scale(0.2, 0.2);
		firstLoad = false;
	}
	player.m_position = maze->currentMazeSprite->getOrigin();
	
	
	player.characterSprite->setPosition(maze->currentMazeSprite->getOrigin());
	player.collisionSprite->setPosition(maze->currentMazeSprite->getOrigin());
}

