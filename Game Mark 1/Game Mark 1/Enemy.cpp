/*
** Last Author: Jordan
** Date Modified: 22/11/19
** Version: 1.00
** Change Log:
*** -------- <15/11/19> 
***	<Jordan> Updated enemy movement. Character in cpp methods and used enemy instead.
** Changes made in order to draw enemy to screen and give movement.
*** -------- <22/11/19>
***	<Jordan> Updated enemy movement. Character in cpp methods and used enemy instead.
** Changes made in order to draw enemy to screen and give movement.
*** --------- End of Changes
*/

#include "Enemy.h"
#include "Collision.hpp"

int Enemy::id = 0;

Enemy::Enemy(){
	//Enemy Character ID and Stats
	enemy_id = id;
	m_type = 0;
	m_health = 0;
	m_speed = 0;
	m_Alive = true;
	spr = new SpriteManager();
	id++;
	//Postion of the Enemy Character
	//x = 0;
	//y = 0;
};


/*
	Pass in where you want the enemy to spawn,type and speed
	Based on the type the enemy will have different stats
*/
void Enemy::spawn(float startX, float startY, int type)
{
	switch(type)
	{
		//TO DO : Load sprite
		case 1: //Ghost
			m_health = 50;
			m_speed = 50;
			characterSprite = spr->GetSprite("Textures/Ghost.png");
			characterSprite->setOrigin(640, 360);
			break;
		case 2: //Null
			m_health = 80;
			m_speed = 20;
			characterSprite = spr->GetSprite("Textures/enemy.png");
			characterSprite->setOrigin(313, 313);
			break;
		default: "Not a valid option";
			break;
	}//End of switch statement.


	//Set enemy location
	characterSprite->setPosition(startX, startY);
	m_position = characterSprite->getPosition();

	//Scale down sprite
	characterSprite->setScale(0.2, 0.2);
}

void Enemy::Attack() {
	//uses a random or predetermined algorithmn to manuplates the enemy character object to attack an player character object
	//the algoritmn determines the type of attack pattern the enemy might for example doing a very slow attack for heavy amount of damage to the player object
	//makes the enemy sprite go into the attack animation
	//it then goes into the gethit function of the player character object and checks if the enemy got hit by returning true or false
	switch (m_type)
	{
		case 1:
			//If player and enemy either 1 or 2 away then do this amount of damage.
			break;
		case 2:
			break;
		default: "Invalid option for player attack ";
			break;
	}
}

void Enemy::Move(float elapsedTime, sf::Vector2f playerlocation)
{
	if (cooldown==true)
	{
		attackCooldownCurrent--;
		if (attackCooldownCurrent <= 0)
		{
			attackCooldownCurrent = attackCooldownMax;
			cooldown = false;
		}
	}

	elapsedTime = .005;
	//uses a random or predetermined algorithmn to manuplates the enemy character object to attack an player character object
	
	float playerX = playerlocation.x;
	float playerY = playerlocation.y;
	//float playerX = playerLocation.x;
	//float playerY = playerLocation.y;

	// Update the zombie position variables
	/* COLLISION HANDLING */
	if(collidingWithWall)
	{ //if sprite is colliding with maze wall.
		characterSprite->setPosition(m_PreviousLocation); //Set the sprite to the last known not colliding location
		m_position = m_PreviousLocation; //reset the m_location
		collidingWithWall = true; //tag with true
	}
	else
	{ //if sprite is NOT colliding with maze wall.
	m_PreviousLocation = characterSprite->getPosition(); //set the uncolliding position
	collidingWithWall = false; //tag with false
	}
	/* END COLLISION HANDLING */
	if (!collidingWithWall && PlayerInRange(playerlocation))
	{
		if (playerY > m_position.y)
		{
			m_position.y = m_position.y +
				m_speed * elapsedTime;
		}

		if (playerY < m_position.y)
		{
			m_position.y = m_position.y -
				m_speed * elapsedTime;
		}
		if (playerX > m_position.x)
		{
			m_position.x = m_position.x +
				m_speed * elapsedTime;
		}
		if (playerX < m_position.x)
		{
			m_position.x = m_position.x -
				m_speed * elapsedTime;
		}

		//Move enemy sprite
		characterSprite->setPosition(m_position);
	}
	else if (collidingWithWall)
	{
		int extraStep = 5;
		int randomLocation = rand() % 4;
		switch (randomLocation)
		{
		case 0:
			m_position.y = m_position.y + extraStep +
				m_speed * elapsedTime;
			break;
		case 1:
			m_position.y = m_position.y - extraStep -
				m_speed * elapsedTime;
			break;
		case 2:
			m_position.x = m_position.x + extraStep +
				m_speed * elapsedTime;
			break;
		case 3:
			m_position.x = m_position.x - extraStep -
				m_speed * elapsedTime;
			break;
		}
		characterSprite->setPosition(m_position);
	}

	//Face the sprite at the angle of the player
	float angle = (atan2(playerY - m_position.y,
		playerX - m_position.x)
		* 180) / 3.141;

	//Set angle
	//characterSprite->setRotation(angle);

}//End of move().


/*
	Calculates the distance between the enemy and player
*/
bool Enemy::PlayerInRange(sf::Vector2f playerLocation)
{
	bool withinRange = false;
	int deltaX = m_position.x - playerLocation.x;
	int deltaY = m_position.y - playerLocation.y;
	int range = 200;

	float powDeltaX = pow(deltaX, 2);
	float powDeltaY = pow(deltaY, 2);
	float powDxDy = powDeltaX + powDeltaY;
	float dy = sqrt(powDxDy);

	if (dy <= range)
	{
		withinRange = true;
		playerInRange = true;
	}


	return withinRange;
}

bool Enemy::GetHit() {
	//After the enemy character object has been attacked by the player character it checks if the character has gotten hit by an opposing object 
	//if enemy character object is hit checks how much health is taking from the player characters object health variable
	//then it goes into the isAlive function and returns into true or false
	return false;

}
//getHit().

/*
void Character::Kill() {
	//if the enemy character isAlive returns false
	//takes the object of the board
	//Destroys object
}
*/