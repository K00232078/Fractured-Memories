#include "GameMenu.h"
#include <iostream>

int GameMenu::MAX_NUMBER_OF_OPTIONS = 3;

GameMenu::GameMenu()
{
	sm = new SpriteManager();
}

/*
	Popluate menuoptions. Then popluate intialize each vector value and give play the value of true so it starts of highlighted.
*/
void GameMenu::InitialiseText()
{
	//Each piece of text in the menu
	menuOptions.push_back(new sf::Text);
	menuOptions.push_back(new sf::Text);
	menuOptions.push_back(new sf::Text);

	IntialiseOptions();
}

/*
	Loops through the menuOptions vecotor.If the index is true then we highlight it red
	else make it white.
	Each index is given a string,font,size and position
	Finally drawing each index.
*/
void GameMenu::draw(sf::RenderWindow* window, float width, float height)
{

	for (int i = 0; i < optionState.size(); i++)
	{
		if (optionState[i] == true)
		{
			menuOptions[i]->setFillColor(sf::Color::Magenta);
			menuOptions[i]->setScale(2,2);
		}
		else
		{
			menuOptions[i]->setFillColor(sf::Color::White);
			menuOptions[i]->setScale(2, 2);
		}
	}

	font.loadFromFile("Fonts/OldLondon.ttf");
	menuOptions[0]->setFont(font);
	menuOptions[0]->setString("Play");
	menuOptions[0]->setCharacterSize(20);
	menuOptions[0]->setPosition(sf::Vector2f(width / 2, height / 3.75 ));

	menuOptions[1]->setFont(font);
	menuOptions[1]->setString("Options");
	menuOptions[1]->setCharacterSize(20);
	menuOptions[1]->setPosition(sf::Vector2f(width / 2, height / 3));

	menuOptions[2]->setFont(font);
	menuOptions[2]->setString("Exit");
	menuOptions[2]->setCharacterSize(20);
	menuOptions[2]->setPosition(sf::Vector2f(width / 2, height / 2.5));


	for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++)
	{
		window->draw(*menuOptions[i]);
	}

}
/*
	Start the menu with play highlighed by giving it the value of true. Set the rest to false for white
*/
void GameMenu::IntialiseOptions()
{
	optionState.push_back(new bool);
	optionState.push_back(new bool);
	optionState.push_back(new bool);

	optionState[0] = true;
	optionState[1] = false;
	optionState[2] = false;
}

/*
	If selectedItemIndex is less then decrement the varaible.
*/
void GameMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		selectedItemIndex--;
	}

	Highlight();
}

/*
	If player presses down button increase selctedItemIndex and update highlighted text
*/
void GameMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_OPTIONS)
	{
		selectedItemIndex++;
	}
	Highlight();
}

//Set every value in the vector to false. Depending on the value of selectedItemIndex one option will be true.
void GameMenu::Highlight()
{
	for (int i = 0; i < optionState.size(); i++)
	{
		optionState[i] = false;
	}
	optionState[selectedItemIndex] = true;
}

/*
	Shows player how to play the game if they select the how to play option in the menu
*/
void GameMenu::HowToPlay(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);

	sf::Sprite* bg = sm->GetSprite("Textures/howto.png");
	bg->setScale(3.2, 1.8);
	window->draw(*bg);
		
	window->display();
}