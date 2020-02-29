/*
** Last Author: Thomas
** Date Modified: 29/11/19
** Version: 0.001
** Change Log:
*** -------- <29/11/19>
***	<Thomas> Added Signiature Head
***	<Thomas> Pulled EnemyMove into a Seperate file.
*** --------- End of Changes
*/

#include "Game.h"
void Game::EnemyMove()
{
	//cout << "Enemy X: " << enemies[0]->m_position.x << endl;
	//cout << "Enemy Y: " << enemies[0]->m_position.y << endl;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (Collision::PixelPerfectTest(*enemies[i]->characterSprite, *player.characterSprite))
		{
			//collision with player
		}
		else
		{
			//not collision with player
		}

		if (Collision::PixelPerfectTest(*enemies[i]->characterSprite, *maze->currentMazeSprite))
		{
			enemies[i]->collidingWithWall = true;
		}
		else
		{
			enemies[i]->collidingWithWall = false;
		}
		enemies[i]->Move(dt.asSeconds(), player.characterSprite->getPosition()); //this is a movement script
	}
}