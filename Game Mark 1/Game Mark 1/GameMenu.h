#include <SFML/Graphics.hpp>
#include "TextManager.h"
#ifndef GAME_MENU
#define GAME_MENU

class GameMenu
{
public:


	GameMenu();
	void InitialiseText();
	void IntialiseOptions();
	void draw(sf::RenderWindow* window, float width, float height);
	void Render(sf::RenderWindow* window);
	void MoveUp();
	void MoveDown(); 
	void HowToPlay(sf::RenderWindow* window);

	int selectedItemIndex = 0;
private: 

	void Highlight();

    static int MAX_NUMBER_OF_OPTIONS; 
	sf::Text menuText;
	sf::Font font;
	vector<sf::Text*> menuOptions;
	vector<bool> optionState;
	TextManager tm;
	SpriteManager* sm;
	sf::Sprite* background;

};
#endif // !GAME_MENU

