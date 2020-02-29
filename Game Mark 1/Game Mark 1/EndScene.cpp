#include "EndScene.h"
#include <iostream>

EndScene::EndScene()
{
	font.loadFromFile("Fonts/BeyondWonderland.ttf");
	setUpGraphics();
}

EndScene::~EndScene()
{
//	delete[] clueManager;
}


EndScene::EndScene(ClueManager* clueMgr, sf::Vector2f resolution)
{
	screenSize = resolution;
	clueManager = clueMgr;
	font.loadFromFile("Fonts/BeyondWonderland.ttf");
	setUpGraphics();
	//calculateLocations();
}

void EndScene::DrawEnd(bool win, sf::RenderWindow* window)
{
	winLoseText.setFont(font);
	solutionText.setFont(font);
	playAgain.setFont(font);
	vector<Clue*> solution = clueManager->ReturnSolution();

	if (win) 
	{
		winLoseText.setString("Congratulations, you won! Now you can be free forever!");
		string solutionTextY = "The murderer was ";
		solutionTextY += solution[0]->name;
		solutionTextY += " with the ";
		solutionTextY += solution[1]->name;
		solutionTextY += " because ";
		solutionTextY += solution[2]->descriptionSolution;
	}
	else
	{
		string solutionTextY = "The murderer was ";
		solutionTextY += solution[0]->name;
		solutionTextY += " with the ";
		solutionTextY += solution[1]->name;
		solutionTextY += " because ";
		solutionTextY += solution[2]->descriptionSolution;
		winLoseText.setString("You Lost");
		solutionText.setString(solutionTextY);

	}
	window->draw(winLoseText);
	window->draw(solutionText);
	window->draw(playAgain);
	for (size_t i = 0; i < 3; i++)
	{
		//std::cout << " Solution: " << solution[i]->clueSprite->getPosition().x << endl;
		window->draw(*solution[i]->clueSprite);
	}
}

void EndScene::setUpGraphics()
{
	//calculateLocations();
	winLoseText.setString("You have Lost!");
	playAgain.setString("Press Escape to quit!");
	winLoseText.setPosition(screenSize.x / 2.7, screenSize.y / 2);
	playAgain.setPosition(screenSize.x / 2.7, screenSize.y / 2 + 160);
	solutionText.setPosition((screenSize.x/2) - 800 , (screenSize.y / 2)+80);
}

void EndScene::calculateLocations()
{
	vector<Clue*> solution = clueManager->ReturnSolution();
	float sizex = screenSize.x;
	float buffer = sizex / 10;
	float spriteSizeX = sizex / 20;
	float spritePercentage = spriteSizeX / 300;
	float accumulation = 0;
	float mult = 2.5;
	accumulation += buffer + 40;
	spriteLocations.push_back(sf::Vector2f(accumulation, screenSize.y / 3));
	accumulation += spriteSizeX + buffer*mult;
	spriteLocations.push_back(sf::Vector2f(accumulation, screenSize.y / 3));
	accumulation += spriteSizeX + buffer*mult;
	spriteLocations.push_back(sf::Vector2f(accumulation, screenSize.y / 3));

	for (size_t i = 0; i < solution.size(); i++)
	{		
		solution[i]->clueSprite->setScale(1, 1);
		solution[i]->clueSprite->setScale(spritePercentage, spritePercentage);
		solution[i]->clueSprite->setPosition(spriteLocations[i]);
		//cout << "Sprite Scale " << i << ":  " << solution[i]->clueSprite->getPosition().x << endl;
	}


}
