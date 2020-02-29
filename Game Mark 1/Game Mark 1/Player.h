#include <iostream>
#include "Character.h"
#include "SpriteManager.h"
#include <cmath>
#include <math.h>
#include "Enemy.h"
#include "Cooldown.h"
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Player : public Character {
protected:
	
	float deg, rad;
	bool pressed = false;
	
public:
	double visibililty;
	sf::Sprite* visionSprite;
	sf::Sprite* attackSprite;
	Cooldown visibility;
	Cooldown attackingAnim;
	Player();

	void spawn(float startX, float startY);
	float distance(int x1, int y1, int x2, int y2);
	//Player Character Behaviour
	virtual void Move(float elapsedTime, sf::Sprite* mazeWall);
	virtual void Attack(Enemy* e);
	virtual bool GetHit();
	/*virtual void Kill();*/

		//Direction the Player is moving when command is pressed
	bool m_UpPressed = false;
	bool m_DownPressed = false;
	bool m_LeftPressed = false;
	bool m_RightPressed = false;

	bool facingUp = false;
	bool facingDown = true;
	bool facingLeft = false;
	bool facingRight = false;
	void switchDirection(int direction);
	void pressReset();
private:
	int attackCooldownCurrent = 0;
	int attackCooldownMax = 20;
	

	bool m_wallCollision = false;
	//Player Sprite
	SpriteManager* sm;
	void collisionDetection(sf::Sprite* mazeWall);
	
}; //End of Player Class
#endif // !ENEMY.H