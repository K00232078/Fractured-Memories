#include <SFML/Graphics.hpp>
#ifndef MENU
#define MENU

class Menu
{
	sf::Sprite s;
	sf::Text menuText;
	sf::Font font;

	Menu();
	void Draw();
	
};
#endif // !MENU
