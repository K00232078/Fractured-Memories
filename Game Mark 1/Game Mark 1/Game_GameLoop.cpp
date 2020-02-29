/*
** Last Author: Thomas
** Date Modified: 29/11/19
** Version: 0.001
** Change Log:
*** -------- <29/11/19>
***	<Thomas> Added Signiature Head
***	<Thomas> Pulled GameLoop into a Seperate file.
*** --------- End of Changes
*/

#include "Game.h"

void Game::GameLoop()
{
	
	sf::Event event;
	while (window->isOpen())
	{//game loop
		
	 // Update the delta time
		Time dt = clock.restart();
		// Update the total game time
		gameTimeTotal += dt;
		// Make a decimal fraction of 1 from the delta time
		dtAsSeconds = dt.asSeconds();
		
		/*JUST LIMITING A FRAME COUNTER*/
		if (frameCount >= 1000)
		{
			frameCount = 0;
		}
		else
		{
			frameCount++;
		}
		/*------------------------------*/

		while (window->pollEvent(event))
		{
			EventHandle(event);
			if (event.type == Event::KeyPressed)
			{
				EventKeyboard(event);
			}
		}
		Update();
		
		//getCenter of player
		camera.setCenter(player.characterSprite->getPosition().x, player.characterSprite->getPosition().y);
	}


}