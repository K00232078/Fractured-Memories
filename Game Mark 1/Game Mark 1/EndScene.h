#include <SFML/Graphics.hpp>
#include "ClueManager.h"
#include <vector>
#ifndef END_SCENE
#define END_SCENE

class EndScene 
{
public:
	EndScene();
	~EndScene();
	EndScene(ClueManager* clueMgr, sf::Vector2f resolution);
	void DrawEnd(bool win, sf::RenderWindow* window);
	void calculateLocations();

	ClueManager* clueManager;
	sf::Text winLoseText;
	sf::Text solutionText;
	sf::Font font;
	sf::Text playAgain;
	std::vector<sf::Vector2f> spriteLocations;

private:
	sf::Vector2f screenSize;
	void setUpGraphics();
	
};

#endif // !END_SCENE

