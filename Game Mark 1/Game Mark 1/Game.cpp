/*
** Last Author: Thomas
** Date Modified: 15/11/19
** Version: 0.3
** Change Log:
*** -------- <15/11/19>
***	<Thomas> Added Constructor Calls
***	<Thomas> Why?: Testing
*** --------- End of Changes
*** -------- <22/11/19>
***	<Jordan> Create and drew enemies to screen
***	<Jordan> Why?: For visual representation for player to see enemies
*** -------- <29/11/19>
***	<Thomas> Ripped out some methods into seperate files.
***	<Thomas> Cleaned up commented out code.
***	<Thomas> added camera for centering on the player.
***	<Thomas> added a resolution that is set in header file so now we have a defined resolution throughout.
***	<Thomas> changed how the game loop works; emulating unity's update function. Use update for events requiring a tick.
***	<Thomas> Why?: Because better
*** -------- <10/12/19>
***	<Jordan> Changed how enemies are drawn to the screen
*** <Jordan> Why?: So we can draw all enemies to the screen in less lines. 
*** <Jordan> Along with if they die they will be removed from the list and not drawn to screen.
*** -------- <19/12/19>
***	<Thomas> Added StoryEngine for handling the string data for text pop ups
***	<Thomas> Added StateManager for handling changing scenes/states
***	<Thomas> Added TextManager for handling pop up texts
***	<Thomas> Added frameCount to count frames (counts up to 1000 and resets to 0) we can use this for timers. I added it for the pop up text blinking chevron
***	<Thomas> Added collisionSprite to player which is being drawn behind the background for a better collision handling.
***	<Thomas> Modified StateManager default state is menu, mainly for me testing menu and text pop up.
*** --------- End of Changes
*/

#include "Game.h"
#include <sstream>
#include <SFML/Graphics.hpp>
Game::Game()
{
	 maze = new Maze();
	spriteManager = new SpriteManager();
	soundManager = new SoundManager();
	textManager = new TextManager();
	stateManager = StateManager();
	levelManager = LevelManager();
	clueManager = new ClueManager();
	inventoryViewer = new InventoryViewer(clueManager);
	endScene = EndScene(clueManager,resolution);

	
	sf::Time time = sf::Time();
	sf::Clock c = sf::Clock();
	camera = View(sf::FloatRect(0, 0, resolution.x, resolution.y));
	gameMenu = new GameMenu();
}

Game::~Game()
{
	delete[] vm;
	delete[] window;
	delete[] spriteManager;
}

void Game::move()
{
	//run through all characters and handle their movements
	//Farming out methods for viewing pleasure
	if (!readingText)
	{
		PlayerMove();
		EnemyMove();
	}		
}


/*
	Create each enemy,where they start and what type they are
	Add them to the vector
*/
void Game::AddEnemies() {
//	enemies = levelManager.enemies;

	//create enemies based on level manager
	enemies.clear();
	for (int i = 0; i < levelManager.getEnemyCount(); i++)
	{
		enemies.push_back(new Enemy());
	}

	int currentLevel = levelManager.currentLevel;
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->spawn(
			levelManager.enemyPositions[currentLevel][i].x,
			levelManager.enemyPositions[currentLevel][i].y,
			1);
	}
}

void Game::AddPowerUp()
{
	int currentLevel = levelManager.currentLevel;
	powerUps.clear();

	for (int i = 0; i < levelManager.getPowerUpCount(); i++)
	{
		powerUps.push_back(new PowerUp());
	}

	for (int i = 0; i < powerUps.size(); i++)
	{
		powerUps[i]->spawn(
			levelManager.powerUpPositions[currentLevel][i].x,
			levelManager.powerUpPositions[currentLevel][i].y,
			i % 3 + 1);
	}
}

void Game::AddClues()
{
	clues.clear();
	int currentLevel = levelManager.currentLevel;
	for (size_t i = 0; i < levelManager.clueAmountPerLevel; i++)
	{
		clues.push_back(new Clue());
	}

	for (size_t i = 0; i < clues.size(); i++)
	{
		cout << "current level x:" << levelManager.cluePositions[currentLevel][i].x << endl;
		clues.at(i)->collisionSprite->setPosition(levelManager.cluePositions[currentLevel][i]);
	}
}

void Game::drawClues()
{
	for (size_t i = 0; i < clues.size(); i++)
	{
		window->draw(*clues.at(i)->collisionSprite);
	}
} 

void Game::CheckForCollisionsWithEnemy()
{
	for(int i=0;i<enemies.size();i++)
	{
		if (Collision::PixelPerfectTest(*enemies.at(i)->characterSprite, *player.characterSprite))
		{
			if (enemies.at(i)->cooldown == false)
			{
				//then hit and switch
				cout << "Enemy Hits Player" << endl;

				player.m_health -= enemies.at(i)->attackStrength;

				if (player.m_health <= 0)
				{
					died = true;
					stateManager.CURRENT_STATE = stateManager.DEATH;
				}
				enemies.at(i)->cooldown = true;
			}
		}
	}
}

void Game::CheckForCollisionsWithClues()
{
	vector<Clue*>::iterator it;
	it = clues.begin();
	for (it = clues.begin(); it < clues.end();)
	{
		if (Collision::PixelPerfectTest(*(*it)->collisionSprite, *player.characterSprite))
		{
			delete* it;
			it = clues.erase(it);

			//and kick off clue pickup.
			textManager->ChangeText("You Picked up A Clue!");
			pickedUp = clueManager->RandomClue();
			cout << "timer:" << textPopUp.max << endl;
			textPopUp.active = true;
			cout << "timer active:" << textPopUp.active << endl;
			readingText = true;
			stateManager.STORY_STATE = stateManager.PICKUP_CLUE;
		}
		else
		{
			it++;
		}
	}
}