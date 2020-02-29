#include <SFML/Graphics.hpp>
using namespace std;
#ifndef CLUE
#define CLUE
class Clue
{
public:
	string name;
	string description;
	string descriptionSolution;
	string type;
	bool pickedUp;
	bool solution;

	sf::Sprite* clueSprite;
	sf::Sprite* collisionSprite;
	sf::Texture* texture;
	Clue();
	//~Clue();
	Clue(string n, string d, string t, string path, string ds);

private:
	void SpriteSetup();
	void SpriteSetup(string path);
};
#endif // !CLUE
