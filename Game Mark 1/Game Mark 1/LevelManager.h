#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "PowerUp.h"
using namespace std;
using namespace sf;


#ifndef LEVEL_MANAGER
#define LEVEL_MANAGER
class LevelManager
{
public:
	/*------VARIABLES-------*/
	int currentLevel = 0;
	int enemiesForCurrentLevel = 0;
	int clueAmountPerLevel = 4;
	
	vector<int> levelEnemyAmounts;
	vector<int> levelPowerUpAmounts;
	vector<vector<Vector2f>> enemyPositions; //enemyPositions[level][enemy]:x,y
	vector<vector<Vector2f>> powerUpPositions; //powerUpPositions[level][powerUp]:x,y
	vector<vector<Vector2f>> cluePositions; //cluePositions[level][clue]:x,y
	vector<Vector2f> playerPosition;
	
	/*-------FUNCTIONS------*/
	LevelManager();
	void Init();
	void ChangeLevel();
	int getEnemyCount();
	int getPowerUpCount();

private:
	int maxLevel = 3;

	void setLevelData();
	void setEnemyData();
	void setPowerUpData();
	void setClueData();
};


#endif // !LEVEL_MANAGER
