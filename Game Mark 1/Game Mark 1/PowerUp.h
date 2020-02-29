#ifndef  POWERUP_H
#define  POWERUP_H

#include <string>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Collision.hpp"

using namespace std;

class PowerUp 
{
public:

	int m_typeID;
	bool m_Spawned;
	Player* player;
	sf::Vector2f pickup;
	sf::Sprite* PowerUpSprite;
	SpriteManager* sm;
	
	//Pass a value into collection and based on the value it will set a power up based on that number.
	PowerUp();
	void collect(Player* p1);
	void collected();
	void spawn(int x, int y,int type);
};

#endif // ! POWER_UP
