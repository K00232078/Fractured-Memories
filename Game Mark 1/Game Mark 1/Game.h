#include "Maze.h"
#include "Player.h"
#include "Clue.h"
#include "ClueManager.h"
#include "Cooldown.h"
#include <vector>
#include "Enemy.h"
#include "PowerUp.h"
#include "Puzzle.h"
#include "StateManager.h"
#include "Collision.hpp"
#include <SFML/Window.hpp>
#include "PowerUp.h"
#include "GameMenu.h"
#include "TextManager.h"
#include "SoundManager.h"
#include "StoryEngine.h"
#include "LevelManager.h"
#include "GameMenu.h"
#include "InventoryViewer.h"
#include "Guess.h"
#include "EndScene.h"
#include <ctime>

#ifndef GAME_H
#define GAME_H

using namespace sf;

class Game
{
public:
	//Declare Constructor(s)
	Game();
	
	//Declare Deconstructor(s)
	~Game();

	//Declare Public Variables
	/* None at the minute */

	//Declare Public Functions
	bool init();
	void move();
	void actions();
	void render();

private:
	//Declare Private Variables
	bool readingText = false;
	bool disableVisionMask = false;
	bool viewingInventory = false;
	float frameCount = 0;
	float screenWidth;
	float screenHeight;
	bool gamePaused = false;
	bool keyLock = true;
	bool firstLoad = true;
	bool died = false;
	bool win = false;
	bool resetLevel = false;

	int keyCooldownCurrent = 0;
	int keyCooldownMax = 3;

	sf::Event event;
	sf::VideoMode* vm;
	sf::RenderWindow* window;
	sf::View camera;
	sf::View HUD;
	sf::Vector2f resolution = sf::Vector2f(1920, 1080);
	sf::Sprite* background;
	sf::Sprite* clue;

	vector<Enemy*> enemies;
	vector<PowerUp*> powerUps;
	vector<Clue*> clues;
	
	SpriteManager* spriteManager;
	SoundManager* soundManager;
	ClueManager* clueManager;
	Clue* pickedUp;
	InventoryViewer* inventoryViewer;

	sf::Sound sound;
	sf::SoundBuffer* buffer;

	Maze* maze;
	Enemy* e1;
	PowerUp* powerup1;
	
	EndScene endScene;
	Cooldown textPopUp;
	Player player;
	StateManager stateManager;
	StoryEngine storyEngine;
	LevelManager levelManager;
	GameMenu* gameMenu;
	TextManager* textManager;
	GameMenu menu;
	

	//Private Methods
	void AddEnemies();
	void AddClues();
	void GameLoop();
	void Update();
	void PlayerMove();
	bool CheckIfAtEnd();
	void EnemyMove();
	void AddPowerUp();
	void CheckForCollisionsWithEnemy();
	void CheckForCollisionsWithClues();
	void playerAttack();
	void playerSpriteChange();
	void SetUpLevel();
	void SpriteSetup();
	void NextLevel();

	//wanting to change things
	void EventHandle(Event event);

	void EventKeyboard(Event event);
	/*----------THIS IS TEMPORARY AND MIGHT NOT WORK-----------*/
	void renderPlay();
	void renderMenu();
	void renderPause();
	void renderPuzzle();
	/*------Draw items------------------*/
	void drawPowerUp();
	void drawMenu();
	void drawClues();
	/*------------------------*/

	void PlayerCollectPowerUp();
	
	bool pickupitem;

	sf::View GameHUD(sf::View HUD, Player* p);

	//Time varaibles
	Clock clock;
	Time dt;
	float dtAsSeconds;
	Time gameTimeTotal;
	
	//State Machine
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
	
	//Guess System
	Guess* guess;
	void GuessSpeech();
	void Guessevent();

	//Declare Private Functions
	/* None at the minute */
};

#endif // !GAME_H
