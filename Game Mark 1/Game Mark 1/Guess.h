#ifndef GUESS
#define GUESS
#include "ClueManager.h"
#include "Clue.h"
#include "SpriteManager.h"
#include "Player.h"
#include "TextManager.h"
#include "StateManager.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

class Guess
{
public:

	//Text show at beggining and after the player makes a guess
	string confirmationText;
	string WinningText;
	string WrongText;
	string PartAnswer;
	string levelSpeech;
	string rightWeapon;
	string rightSuspect;
	string rightMotive;
	string NoGuessesLeft;
	int level = 0; //Current level
	bool speechSaid = false; //If they enemy has talked
	bool death = false; //Has the player failed to guess the killer
	bool RightGuess = false;

	SpriteManager* spriteManager;
	ClueManager* clues;
	sf::RenderWindow* window;
	int frameCount;
	TextManager* tm;
	sf::Event event;
	StateManager* stateManager;
	
	bool answer = false; //Has the player guessed each clue
	bool GuessCompleted;//Player guess confirmed?

	//Character and background sprites & Textures
	sf::Sprite backgroundSprite;
	sf::Sprite enemySprite;
	sf::Sprite playerSprite;

	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	
	
	int itemSelected;//Current item selected
	int maxNoOptions;//Number of clues 
	int guessSelctionState = 0; //Check if the player is currently guessing weapon,suspect or motive
	vector<Clue> selectedItemList;//Store guessed clues

	Guess(ClueManager* clue, sf::RenderWindow* windows,int framecount);
	void init();
	void setupGuessWindow();
	void checkState();
	void DrawSelectedItems();
	void confirmAnswer(StateManager stateManager);
	void ResetClueScale();
	void moveRight();
	void moveLeft();
	void itemSelcted();
	void LevelSpeech();

private:
	void popluateSelectedItemList();
	void spriteSetup();
	void displayWeapons();
	void displaySuspects();
	void displayMotives();
	void highlight();
	void CheckAnswer(StateManager stateManager);
	void ResetAnswer();
	void displayText(string path);
};
#endif // !GAME_GUESS
