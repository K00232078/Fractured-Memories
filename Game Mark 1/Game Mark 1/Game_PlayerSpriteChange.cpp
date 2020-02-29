#include "Game.h"

/*
	Handles sprite changes when the player uses WASD
	Checks if a button has been pressed and the player isnt already in that state
	If the scale has not been setup then we do so
	Finally we switch their direction
*/
void Game::playerSpriteChange()
{
	if (player.m_UpPressed && !player.facingUp)
	{
		player.characterSprite = spriteManager->GetSprite("Textures/Luna Back.png");
		if (player.characterSprite->getScale().x==1)
		{
			player.characterSprite->setOrigin(640, 360);
			player.characterSprite->scale(0.2, 0.2);
		}		
		player.switchDirection(1);
	}
	else if (player.m_DownPressed && !player.facingDown)
	{
		player.characterSprite = spriteManager->GetSprite("Textures/Luna Front.png");
		if (player.characterSprite->getScale().x == 1)
		{
			player.characterSprite->setOrigin(640, 360);
			player.characterSprite->scale(0.2, 0.2);
		}
		player.switchDirection(0);
	}
	else if (player.m_LeftPressed && !player.facingLeft)
	{
		player.characterSprite = spriteManager->GetSprite("Textures/Luna Left.png");
		if (player.characterSprite->getScale().x == 1)
		{
			player.characterSprite->setOrigin(640, 360);
			player.characterSprite->scale(0.2, 0.2);
		}
		player.switchDirection(2);
	}
	else if (player.m_RightPressed && !player.facingRight)
	{
		player.characterSprite = spriteManager->GetSprite("Textures/Luna Right.png");
		if (player.characterSprite->getScale().x == 1)
		{
			player.characterSprite->setOrigin(640, 360);
			player.characterSprite->scale(0.2, 0.2);
		}
		player.switchDirection(3);
	}
}



