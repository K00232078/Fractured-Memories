#include <SFML/Graphics/Drawable.hpp>
#include <string>
#include "SpriteManager.h"
#include <SFML/Graphics.hpp>

#ifndef TEXT_MANAGER
#define TEXT_MANAGER

class TextManager : public sf::Drawable
{
public:
	TextManager();
	TextManager(sf::Vector2f windowResolution);
	void ChangeText(std::string text);
	void Init();
	void Render(sf::RenderWindow* window, int frameCount,string textToDisplay);
	SpriteManager spriteManager;
	std::string applyText;
	sf::Vector2f resolution;
	sf::RectangleShape backing;
	sf::Text popUpText;
	sf::Font font;
	sf::Sprite* chevron;
	int timer = 1;
	bool chevronBlink = false;
private:
	void manageString();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !TEXT_MANAGER

