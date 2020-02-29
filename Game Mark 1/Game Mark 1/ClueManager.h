#include "Clue.h"
#include "SpriteManager.h"
#include <SFML/Graphics.hpp>

#ifndef CLUE_MANAGER
#define CLUE_MANAGER
class ClueManager
{
public:
	ClueManager();
	vector<Clue*> weapons;
	vector<Clue*> suspects;
	vector<Clue*> motives;
	SpriteManager spriteManager;
	sf::Sprite* pickedUpSprite;

	Clue* RandomClue(string type);
	Clue* RandomClue();
	
	vector<Clue*> ReturnSolution();


private:
	void SetUpWeapons();
	void SetUpMotives();
	void SetUpSuspects();
	void SetUpSprites();
	int RandomNumber(int size);
};
#endif // !CLUE_MANAGER

