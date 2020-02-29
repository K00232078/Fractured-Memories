#include "TextManager.h"
#include <iostream>

TextManager::TextManager()
{
	spriteManager = SpriteManager();
	TextManager(sf::Vector2f(1920, 1080));
}

TextManager::TextManager(sf::Vector2f windowResolution)
{
	resolution = windowResolution;
	Init();
	applyText = "Test";
}

void TextManager::ChangeText(std::string text)
{
	applyText = text;
	popUpText.setString(applyText);
}

void TextManager::Init()
{
	/*Size = 25% y  & 70% x*/
	sf::Vector2f size = sf::Vector2f(resolution.x * .7, resolution.y * .25);
	backing = sf::RectangleShape(size);
	backing.setPosition(1,1);
	backing.setSize(size);
	backing.setFillColor(sf::Color::Black);
	backing.setOutlineColor(sf::Color::Color(255, 0, 255));
	backing.setOutlineThickness(5);
	
	font.loadFromFile("Fonts/OldLondon.ttf");
	popUpText.setFont(font);
	popUpText.setFillColor(sf::Color::White);
	popUpText.setCharacterSize(20);
	popUpText.setPosition(backing.getOrigin());
	popUpText.setString(applyText);
}

void TextManager::Render(sf::RenderWindow* window, int frameCount, std::string textToDisplay)
{
	//cout << frameCount << endl;
	/*Size = 25% y  & 70% x*/
	//sf::Vector2f size = sf::Vector2f(resolution.x * .8, resolution.y * .25);
	chevron = spriteManager.GetSprite("Textures/chevron-smoll.png");
	chevron->setOrigin(96.5, 91);
	chevron->setScale(0.3, 0.3);
	chevron->setPosition((window->getSize().x)-150, (window->getSize().y)-100);


	sf::Vector2f size = sf::Vector2f((window->getSize().x) * .9, (window->getSize().y)*.25);
	backing.setSize(size);
	//backing.setPosition(resolution.x - size.x, resolution.y - size.y);
	// 
//	backing.setOrigin(size.x / 2, size.y / 2);
	backing.setPosition((window->getSize().x)*.05, (window->getSize().y)*.70);
	
	backing.setFillColor(sf::Color::Black);
	backing.setOutlineColor(sf::Color::Color(83, 0, 166));
	backing.setOutlineThickness(5);

	font.loadFromFile("Fonts/BlackwoodCastle.ttf");
	popUpText.setFont(font);
	popUpText.setLineSpacing(2);
	popUpText.setFillColor(sf::Color::White);
	popUpText.setCharacterSize(30);
	//popUpText.setPosition(backing.getPosition().x + (size.x/2), backing.getPosition().y + (size.y / 2));
	popUpText.setPosition(backing.getPosition().x + 10, backing.getPosition().y + 5 );
	

	applyText = textToDisplay;
	manageString();

	popUpText.setString(applyText);
	window->draw(backing);
	window->draw(popUpText);
	/*----BLINKING CHEVRON ------*/
	if (frameCount % 30 == 0)
	{ /*Blinking chevron*/
		chevronBlink = !chevronBlink;
	}
	if (chevronBlink)
	{
		window->draw(*chevron);
	}
	/*----------------------------*/
}


void TextManager::manageString()
{
	//test length of string.
	//for every N amount of letters add a /n
	std::vector<char> displayString = std::vector<char>();
	int n = 150;
	bool waitForSpace = false;
	/*-------DECONSTRUCT STRING---------*/
	for (size_t i = 0; i < applyText.length(); i++)
	{
		if (i % n == 0 && i != 0)
		{
			waitForSpace = true;
		}

		if (waitForSpace)
		{
			char a = applyText.at(i);
			if (a==' ')
			{
				displayString.push_back('\n');
				waitForSpace = false;
			}
			else
			{
				displayString.push_back(applyText.at(i));
			}
		}
		else
		{
			displayString.push_back(applyText.at(i));
		}
	}
	/* reconstruct string */
	std::string temp = "";
	for (size_t i = 0; i < displayString.size(); i++)
	{
		temp += displayString.at(i);
	}

	applyText = temp;
}

void TextManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(backing, states);
	target.draw(popUpText, states);
}
