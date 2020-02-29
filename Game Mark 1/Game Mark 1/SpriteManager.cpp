/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.001
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Created File
*** --------- End of Changes
*/
#include "SpriteManager.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		delete[] sprites[i];
	}
	for (int i = 0; i < textures.size(); i++)
	{
		delete[] textures[i];
	}
}

sf::Sprite* SpriteManager::SetSprite(string path)
{
	sf::Texture* texture;
	sf::Sprite* sprite;
	//create a new one
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile(path);
	texture->setSmooth(true);
	sprite->setTexture(*texture);

	//and add it to the lists
	sprites.push_back(sprite);
	textures.push_back(texture);
	lookup.push_back(path);
	return sprite;
}

sf::Sprite* SpriteManager::GetSprite(string path)
{ //DONT PUT IN THE WRONG PATH FFS!
	sf::Sprite* sprite;
	sprite = nullptr;
	if (SpriteExist(path) == -1)
	{//if it doesn't exist
		sprite = SetSprite(path);
	}
	else
	{//if it does exist
		sprite = sprites[SpriteExist(path)];
	}
	return sprite;
}

int SpriteManager::SpriteExist(string path)
{
	int returnValue = -1;
	for (int i = 0; i < lookup.size(); i++)
	{
		if (lookup[i].compare(path) == 0)
		{//compare returns 0 if two strings are the same
			returnValue = i; //returning the index of the sprite
		}
	}
	return returnValue;
}
