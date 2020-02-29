#include "Game.h"
void Game::renderPlay()
{ //this is called on every tick while game is in the play state
	CheckForCollisionsWithEnemy();
	CheckForCollisionsWithClues();
	if (player.visibility.active)
	{
		player.visibility.Tick();
	}
	window->clear(sf::Color::White);
	window->setView(camera);

	/*------------START DRAW STUFF---------------*/


	//draw collision sprite
	window->draw(*player.collisionSprite);
	//draw background on top of the collision sprite to hide it
	window->draw(*background);

	//Draw maze wall to screen
	window->draw(*maze->currentMazeSprite);

	//Draw characters to Screen
	window->draw(*player.characterSprite);
	if (player.attackingAnim.active == true)
	{
		player.attackingAnim.Tick();
		window->draw(*player.attackSprite);
	}

	drawPowerUp();
	drawClues();

	/*
		Loop through each enemy and if they are alive then draw to screen.
		Else delete them from the vector.
		If they enemy is alive check if the player has attacked near that enemy.
	*/
	vector<Enemy*>::iterator it;
	it = enemies.begin();
	for (it = enemies.begin(); it < enemies.end();)
	{
		if (!(*it)->IsAlive())
		{
			player.Attack(*it);
			window->draw(*(*it)->characterSprite);
			it++;
		}
		else
		{
			delete* it;
			it = enemies.erase(it);

			
			buffer = soundManager->GetAudio("Audios/skeleton_death.wav");
			if (!buffer->loadFromFile("Audios/skeleton_death.wav"))
			{
				cout << "Error Audio didn't play. \n" << endl;
			}
			
			sound.setBuffer((*buffer));
			sound.play();
		}
	}

	//Draw [x] to Screen
	//window->draw(*[x]); //Template
	//want to put this vision sprite above everything
	if (player.visibility.active)
	{
		player.visionSprite->setScale(player.visibililty, player.visibililty);
	}
	else
	{
		player.visionSprite->setScale(2, 2);
	}
	
	if (!disableVisionMask)
	{
		window->draw(*player.visionSprite);
	}

	GameHUD(HUD, &player);
	
	/*------------END DRAW STUFF---------------*/
	/*------------DISPLAY STUFF---------------*/

	window->display();
	
	/*----------END DISPLAY AND END OF RENDERER----------*/
	/*--------! No more code needed beyond display !------*/
}