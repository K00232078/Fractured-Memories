#include "LevelManager.h"

LevelManager::LevelManager()
{	
	setLevelData();
	//Init();

}

void LevelManager::Init()
{
	setEnemyData();
	setPowerUpData();
	setClueData();
}

void LevelManager::ChangeLevel()
{
	if (currentLevel != maxLevel)
	{
		currentLevel++;
		Init();
	}
	else
	{
		cout << "End of game" << endl;
	}
}

int LevelManager::getEnemyCount()
{
	return levelEnemyAmounts[currentLevel];
}

int LevelManager::getPowerUpCount()
{
	return levelPowerUpAmounts[currentLevel];
}

void LevelManager::setLevelData()
{
	levelEnemyAmounts.push_back(5); /* Level 1 */
	levelPowerUpAmounts.push_back(2);

	levelEnemyAmounts.push_back(5); /* Level 2 */
	levelPowerUpAmounts.push_back(2);

	levelEnemyAmounts.push_back(5); /* Level 3 */
	levelPowerUpAmounts.push_back(2);


	for (int i = 0; i < maxLevel; i++)
	{
		enemyPositions.push_back(vector<Vector2f>());
		powerUpPositions.push_back(vector<Vector2f>());
		cluePositions.push_back(vector<Vector2f>());
	}

	for (int i = 0; i < maxLevel; i++)
	{
		for (int j = 0; j < levelEnemyAmounts[i]; j++)
		{
			enemyPositions[i].push_back(Vector2f());
		}

		for (int j = 0; j < levelPowerUpAmounts[i]; j++)
		{
			powerUpPositions[i].push_back(Vector2f());
		}

		for (int j = 0; j < clueAmountPerLevel; j++)
		{
			cluePositions[i].push_back(Vector2f());
		}
	}


	setEnemyData();
	setPowerUpData();
	setClueData();
}

void LevelManager::setEnemyData()
{
	/* Level 1 */
	enemyPositions[0][0] = Vector2f(903, 1083);
	enemyPositions[0][1] = Vector2f(1113, 637);
	enemyPositions[0][2] = Vector2f(1431, 443);
	enemyPositions[0][3] = Vector2f(345, -321);
	enemyPositions[0][4] = Vector2f(1, 237);

	/* Level 2 */
	enemyPositions[1][0] = Vector2f(661, 73);
	enemyPositions[1][1] = Vector2f(1123, 929);
	enemyPositions[1][2] = Vector2f(1461, 677);
	enemyPositions[1][3] = Vector2f(-141, 47);
	enemyPositions[1][4] = Vector2f(-139, 643);

	/* Level 3 */
	enemyPositions[2][0] = Vector2f(621, -61);
	enemyPositions[2][1] = Vector2f(189, 689);
	enemyPositions[2][2] = Vector2f(895, 15);
	enemyPositions[2][3] = Vector2f(1471, 285);
	enemyPositions[2][4] = Vector2f(347, 1493);
	
}

void LevelManager::setPowerUpData()
{
	/* Level 1 */
	powerUpPositions[0][0] = Vector2f(-65, 401);
	powerUpPositions[0][1] = Vector2f(15, 1263);
	
	/* Level 2 */
	powerUpPositions[1][0] = Vector2f(991, 441);
	powerUpPositions[1][1] = Vector2f(641, 45);

	/* Level 3 */
	powerUpPositions[2][0] = Vector2f(1293, 363); //heart
	powerUpPositions[2][1] = Vector2f(391, 1081); //light
	
}

void LevelManager::setClueData()
{
	/* Level 1 */
	cluePositions[0][0] = Vector2f(-193,1065);
	cluePositions[0][1] = Vector2f(1439,783);
	cluePositions[0][2] = Vector2f(-195,381);
	cluePositions[0][3] = Vector2f(-53,631);

	/* Level 2 */
	cluePositions[1][0] = Vector2f(977, 731);
	cluePositions[1][1] = Vector2f(-205, 1106);
	cluePositions[1][2] = Vector2f(818, 1450);
	cluePositions[1][3] = Vector2f(160, -58);
	
	/* Level 3 */
	cluePositions[2][0] = Vector2f(1145, 74);
	cluePositions[2][1] = Vector2f(1161, 1292);
	cluePositions[2][2] = Vector2f(322, 861);
	cluePositions[2][3] = Vector2f(0, 0);
}
