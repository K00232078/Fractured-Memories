#include "Game.h"

void Game::render()
{
	window->clear(sf::Color::White);
	window->setView(camera);

	/*------------START DRAW STUFF---------------*/
	//Draw maze background to screen
	window->draw(*maze->currentMazeSprite);

	//Draw characters to Screen
	window->draw(*player.characterSprite);
	
	//window->draw(*enemies[0]->characterSprite);
	
	/*if (powerup1->m_Spawned == true)
	{
		window->draw(*powerup1->PowerUpSprite);
	}*
	*/
	GameHUD(HUD,&player);
	/*
		Use an iterator to go through the vector of enemies
		If the enemy is alive then draw enemy to the screen and move them.
		Else delete them from the list.
	*/
	vector<Enemy*>::iterator it;
	it = enemies.begin();
	for (it=enemies.begin(); it < enemies.end();)
	{
		if (!(*it)->IsAlive())
		{
			player.Attack(*it);
			window->draw(*(*it)->characterSprite);
			EnemyMove();
			it++;
		}
		else
		{
			delete* it;
			it = enemies.erase(it);
		}		
	}

	

	//Draw [x] to Screen
	//window->draw(*[x]); //Template
	//want to put this vision sprite above everything
	player.visionSprite->setScale(player.visibililty, player.visibililty);
	window->draw(*player.visionSprite);
	GameHUD(HUD, &player); // Take your own version of this line
	/*------------END DRAW STUFF---------------*/
	/*------------DISPLAY STUFF---------------*/
	window->display();
	/*----------END DISPLAY AND END OF RENDERER----------*/
	/*--------! No more code needed beyond display !------*/
}//End of Render

void Game::drawPowerUp()
{
	vector<PowerUp*>::iterator it, it1;
	it = powerUps.begin();
	it1 = powerUps.begin();
	
		for (it = powerUps.begin(); it < powerUps.end();)
		{
			if ((*it)->m_Spawned == true)
			{
				
				window->draw(*(*it)->PowerUpSprite);
				(*it)->collect(&player);
				it++;
			}
			else
			{
				delete* it;
				it = powerUps.erase(it);
				
			}//End of else statement
			
			
			
		}//End of for loop

}