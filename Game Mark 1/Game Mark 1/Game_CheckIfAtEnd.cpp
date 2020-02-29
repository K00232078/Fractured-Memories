#include "Game.h"

bool Game::CheckIfAtEnd()
{

	/* Ideally get boundary */
	bool atEnd = false;
	int level = levelManager.currentLevel; //could be created from a level manager
	switch (level)
	{
	case 0:
		if (player.m_position.x > 587 && player.m_position.x < 907)
		{
			if (player.m_position.y < -499)
			{
				//switch state
				atEnd = true;
			}
		}
		break;
	case 1:
		if (player.m_position.x > 577 && player.m_position.x < 705)
		{
			if (player.m_position.y < -527)
			{
				//switch state
				atEnd = true;
			}
		}
		break;
	case 2:
		if (player.m_position.y > 803 && player.m_position.y < 825)
		{
			if (player.m_position.x < -478)
			{
				//switch state
				atEnd = true;
			}
		}
		break;
	default:
		break;
	}

	return atEnd;
}