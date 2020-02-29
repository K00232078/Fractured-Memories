#include "InventoryViewer.h"
#include <iostream>

InventoryViewer::InventoryViewer()
{

}

InventoryViewer::InventoryViewer(ClueManager* clueManager)
{
	this->clueManager = clueManager;
	InitialisePositions();
}

void InventoryViewer::Draw(sf::RenderWindow* window)
{
	InitialisePositions();
	window->draw(backing);
	for (int i = 0; i < clueManager->motives.size(); i++)
	{
		window->draw(*clueManager->motives[i]->clueSprite);
		if (clueManager->motives[i]->pickedUp)
		{
			clueManager->pickedUpSprite->setScale(clueManager->motives[i]->clueSprite->getScale());
			clueManager->pickedUpSprite->setPosition(clueManager->motives[i]->clueSprite->getPosition().x, clueManager->motives[i]->clueSprite->getPosition().y);
			window->draw(*clueManager->pickedUpSprite);
		}
	}
	for (int i = 0; i < clueManager->weapons.size(); i++)
	{
		window->draw(*clueManager->weapons[i]->clueSprite);
		if (clueManager->weapons[i]->pickedUp)
		{
			clueManager->pickedUpSprite->setScale(clueManager->weapons[i]->clueSprite->getScale());
			clueManager->pickedUpSprite->setPosition(clueManager->weapons[i]->clueSprite->getPosition().x, clueManager->weapons[i]->clueSprite->getPosition().y);
			window->draw(*clueManager->pickedUpSprite);
		}
	}

	for (int i = 0; i < clueManager->suspects.size(); i++)
	{
		window->draw(*clueManager->suspects[i]->clueSprite);
		if (clueManager->suspects[i]->pickedUp)
		{
			clueManager->pickedUpSprite->setScale(clueManager->suspects[i]->clueSprite->getScale());
			//clueManager->pickedUpSprite->setPosition(clueManager->suspects[i]->clueSprite->getPosition().x - (spriteSize / 2.25), clueManager->suspects[i]->clueSprite->getPosition().y - (spriteSize / 1.99));
			clueManager->pickedUpSprite->setPosition(clueManager->suspects[i]->clueSprite->getPosition().x, clueManager->suspects[i]->clueSprite->getPosition().y);
			window->draw(*clueManager->pickedUpSprite);
		}
	}
	
}

void InventoryViewer::InitialisePositions()
{
	//std::cout << "Initialised" << std::endl;
	sf::Vector2f resolution = sf::Vector2f(1920, 1080);
	sf::Vector2f size = sf::Vector2f(resolution.x * .40, resolution.y * .50);
	sf::Vector2f backingPosition = sf::Vector2f(resolution.x - (size.x + 275), 25);
	backing.setPosition(backingPosition);
	backing.setSize(size);
	backing.setFillColor(sf::Color::Yellow);
	backing.setOutlineColor(sf::Color::Color(255, 0, 255));
	backing.setOutlineThickness(5);
	
	float accumulation = 0;
	
	float totalWidth = backing.getSize().x;
	//cout << "Width: " << totalWidth << endl;
	spriteSize = ((totalWidth * 0.07));
	float spriteScalePercentage = spriteSize / 600;
	float buffer = spriteSize;
	float buffer4 = (totalWidth - spriteSize - 100) / 4;

	

	
	for (int i = 0; i < clueManager->weapons.size(); i++)
	{
		if (i == 0)
		{
			accumulation += backingPosition.x + (buffer*4);
		}
		else
		{
			accumulation += spriteSize + buffer;
		}
		clueManager->weapons[i]->clueSprite->setScale(1, 1);
		clueManager->weapons[i]->clueSprite->setScale(spriteScalePercentage, spriteScalePercentage);
		clueManager->weapons[i]->clueSprite->setPosition(accumulation, backingPosition.y + spriteSize);
	}

	accumulation = 0;

	for (int i = 0; i < clueManager->motives.size(); i++)
	{
		if (i == 0)
		{
			accumulation += backingPosition.x + buffer;
		}
		else
		{
			accumulation += spriteSize + buffer;
		}
		clueManager->motives[i]->clueSprite->setScale(1, 1);
		clueManager->motives[i]->clueSprite->scale(spriteScalePercentage, spriteScalePercentage);
		clueManager->motives[i]->clueSprite->setPosition(accumulation, backingPosition.y + spriteSize*3);
	}

	accumulation = 0;
	
	for (int i = 0; i < clueManager->suspects.size(); i++)
	{
		if (i == 0)
		{
			accumulation += backingPosition.x + (buffer*4);
		}
		else
		{
			accumulation += spriteSize + buffer;
		}
		clueManager->suspects[i]->clueSprite->setScale(1, 1);
		clueManager->suspects[i]->clueSprite->scale(spriteScalePercentage, spriteScalePercentage);
		clueManager->suspects[i]->clueSprite->setPosition(accumulation, backingPosition.y + spriteSize * 5);
	}
}

void InventoryViewer::CheckCheckedClues()
{
}
