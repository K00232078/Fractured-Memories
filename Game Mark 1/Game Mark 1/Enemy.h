/*
** Last Author: Jordan
** Date Modified: 15/11/19
** Version: 1.00
** Change Log: 
*** -------- <15/11/19>
***	<Jordan> Added hit,isAlive & spawn method.
***	<Jordan> Character in cpp methods and used enemy instead.
** Changes made in order to draw enemy to screen and give movement.
*** --------- End of Changes
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"
#include "SpriteManager.h"
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include <SFML/System/Vector2.hpp>
using namespace std;

class Enemy : public Character {

protected:


public:
	
	//bool m_Alive;//Is enemy alive?
	//int m_type;//What type of monster?.
	//float m_Health; //Enemy health
	//int m_Speed;//How fast is the enemy?

	Enemy();

	SpriteManager* spr;

	//Player Character Behaviour
	void Move(float elapsedTime, sf::Vector2f playerlocation);
	virtual bool GetHit();
	virtual void Attack();
	bool PlayerInRange(sf::Vector2f playerLocation);
	/*bool hit();*/
	bool collidingWithWall = false;
	void spawn(float startX, float startY, int type);
	bool playerInRange = false;
	int enemy_id;
	bool cooldown = true;
	int attackStrength = 1;
private:
	int attackCooldownCurrent = 100 ;
	int attackCooldownMax = 100;
	float distance(int x1, int y1, int x2, int y2);
	sf::Sprite* attackSprite;
	static int id;

};
#endif // !ENEMY.H