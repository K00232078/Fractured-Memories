/*
** Last Author: Thomas
** Date Modified: 29/11/19
** Version: 0.001
** Change Log:
*** -------- <29/11/19>
***	<Thomas> Added Signiature Head
***	<Thomas> Pulled PlayerMove into a Seperate file.
*** --------- End of Changes
*/
#include "Game.h"
void Game::PlayerMove()
{
	if (!readingText)
	{
		player.Move(dtAsSeconds, maze->currentMazeSprite);
		playerSpriteChange();
		player.characterSprite->setPosition(player.m_position); /* Don't remove this, it creates flickering */

		/*If player position x between A&B && player position y less than C change to puzzle*/
		/*Each level will be different so move this to a method to check end */
		if (CheckIfAtEnd())
		{
			
			//stateManager.CURRENT_STATE = stateManager.PUZZLE;
			stateManager.CURRENT_STATE = stateManager.GUESS_KILLER;
		}
		//cout << "Health:" << player.m_health << endl;
		/*
		if (Collision::PixelPerfectTest(*player.collisionSprite, *clue))
		{

		}*/
		//PowerUpCollison();
	}
}
