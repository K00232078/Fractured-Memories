#include "Player.h"
#include <Windows.h>
#include "Collision.hpp"

Player::Player() : Character()
{
	//Player Character ID and Stats
	m_type = 0;
	m_health = 6;
	m_speed = 500; //Changed from 200 to 500 for testing
	m_Alive = true;
	visibility = Cooldown(400);
	attackingAnim = Cooldown(10);
	/*defence = 0;
	strength = 0;*/

	sm = new SpriteManager();
	//Postion of the Player Character
	//Used for Player Character visibility
	visibililty = 2;
	characterSprite = sm->GetSprite("Textures/Luna front.png");
	characterSprite->setOrigin(256, 256);

	collisionSprite = sm->GetSprite("Textures/Luna Collision.png");
	collisionSprite->setOrigin(256, 256);

	attackSprite = sm->GetSprite("Textures/LunaAttack.png");
	attackSprite->setOrigin(303, 303);
	attackSprite->setScale(0.2, 0.2);
	

	visionSprite = sm->GetSprite("Textures/visionSprite_05.png");
	visionSprite->setOrigin(800, 500);
	visionSprite->setScale(visibililty,visibililty);
	visionSprite->setPosition(m_position);

	/*attackSprite = sm->GetSprite("Textures/playerAttackImage.png");
	attackSprite->setOrigin(0, 150);
	attackSprite->setScale(0.2, 0.2);
	attackSprite->setPosition(m_position);*/
}

void Player::Attack(Enemy* e) {
	//takes in inputs from the keyboard or controller to manuplates the player sprite to attack an enemy object
	//makes the character sprite go into the attack animation
	//on the keyboard it would be mapped to a keys like space or z,x,c
	//on the dpad it would mappled to the circle or b button
	//go into the get hit function of the enemy object and checks if the enemy got hit returning true or false
	//cout << "Distance: " << distance(m_position.x, m_position.y, e->m_position.x, e->m_position.y) << endl;

	if (attackCooldownCurrent < attackCooldownMax)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			attackingAnim.active = true;
			if (distance(m_position.x, m_position.y, e->m_position.x, e->m_position.y) < 75)
			{
				/*
				cout << endl << "Enemy " << e->enemy_id << " is within crusading distance!" << endl;
				cout << "Player Attacks enemy :" << e->enemy_id << endl;
				cout << "Distance to Enemy " << e->enemy_id << ": " << distance(m_position.x, m_position.y, e->m_position.x, e->m_position.y) << endl;
				cout << "Enemy " << e->enemy_id << " Location: " << e->m_position.x << "," << e->m_position.y << endl;
				*/
				e->m_health -= 25;
				//cout << "Enemy "<< e->enemy_id <<" Health: " << e->m_health << endl;
				attackCooldownCurrent = attackCooldownMax*2;

				//attackSprite = sm->GetSprite("Textures/playerAttackImage.png");
				//attackSprite->setOrigin(0, 150);
				//attackSprite->setScale(0.2, 0.2);
				attackSprite->setPosition(m_position);
			}
		}
	}
	else
	{
		attackCooldownCurrent--;
		//attackSprite->setScale(0, 0);
	}
	//cout << "Distance: " << distance(m_position.x, m_position.y, e->m_position.x, e->m_position.y) << endl;
	
}

float Player::distance(int x1, int y1, int x2, int y2)
{
	/*x1y1 = player; x2y2=enemy*/
	float deltax = x1 - x2;
	float deltay = y1 - y2;
	float dist = deltax + deltay;
	if (dist < 0)
	{
		dist *= -1;
	}
	//return dist;

	float powDeltaX = pow(deltax, 2);
	float powDeltaY = pow(deltay, 2);
	float powDxDy = powDeltaX + powDeltaY;
	float dy = sqrt(powDxDy);
	return dy;
	//return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) * 1.0);
}

bool Player::GetHit()
{
	return false;
}

void Player::spawn(float startX, float startY) {
	m_position.x = startX;
	m_position.y = startX;
	characterSprite->setPosition(m_position);
	//visionSprite->setPosition(0,0);
	m_health = 100;
	m_speed = 1000;
}

void Player::switchDirection(int direction)
{
	facingUp = false;
	facingDown = false;
	facingLeft = false;
	facingRight = false;

	switch (direction)
	{
	case 0:
		facingDown = true;
		break;
	case 1:
		facingUp = true;
		break;
	case 2:
		facingLeft = true;
		break;
	case 3:
		facingRight = true;
		break;
	}
}

void Player::pressReset()
{
	m_UpPressed = false;
	m_DownPressed = false;
	m_LeftPressed = false;
	m_RightPressed = false;
}

void Player::collisionDetection(sf::Sprite* mazeWall)
{
	//move this to new method/file
	if (Collision::PixelPerfectTest(*collisionSprite, *mazeWall))
	{ //if player sprite is colliding with maze wall.
		collisionSprite->setPosition(m_PreviousLocation); //Set the sprite to the last known not colliding location
		characterSprite->setPosition(m_PreviousLocation); //Set the sprite to the last known not colliding location
		m_position = m_PreviousLocation; //reset the m_location
		m_wallCollision = true; //tag with true
	}
	else
	{ //if player sprite is NOT colliding with maze wall.
		m_PreviousLocation = collisionSprite->getPosition(); //set the uncolliding position
		m_wallCollision = false; //tag with false
	}
}

void Player::Move(float elapsedTime, sf::Sprite* mazeWall) {
	rad = (3.1415926536 / 180) * characterSprite->getRotation();
	
	//Are we using elapsed time?
	/* COLLISION HANDLING */
	collisionDetection(mazeWall);
	/* END COLLISION HANDLING */
	/* ----- THIS WORKS ---- */
	if (!m_wallCollision)
	{//if you aren't colliding take input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			pressReset();
			m_UpPressed = true;
			m_position.y -= (m_speed * elapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			pressReset();
			m_DownPressed = true;
			m_position.y += (m_speed * elapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			pressReset();
			m_LeftPressed = true;
			m_position.x -= (m_speed * elapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			pressReset();
			m_RightPressed = true;
			m_position.x += (m_speed * elapsedTime);
		}
	}
	// Calculate the angle the player is facing
	float angle = rad;
	characterSprite->setRotation(angle);



	/* END COLLISION HANDLING */
	if (!m_wallCollision)
	{//if you are not colliding with a wall, set sprite
		characterSprite->setPosition(m_position);
		collisionSprite->setPosition(m_position);
		attackSprite->setPosition(m_position);
		visionSprite->setPosition(m_position);
//		attackSprite->setPosition(m_position);
	}
}

//void Player::Kill() {
//	//if the player character isAlive returns false
//	//takes the object of the board
//	//Destroys object
//	//goes into a game over screen
//	//destorys the boards and bring users back to menu
//
//}

