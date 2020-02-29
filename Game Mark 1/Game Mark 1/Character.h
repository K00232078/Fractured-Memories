#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
class Character
{
public:
	float m_health; //health of the character
	int m_speed; //speed stat of the character
	int defence; //defence stat of the character
	int strength; //strength stat of the character
	int m_type; //identification of the character
	bool m_Alive;//Is character alive?
	sf::Vector2f m_PreviousLocation;	

	Character();
	~Character();
	sf::Vector2f m_position;//Positon of character
	sf::Sprite* characterSprite; // pointer to the sprite
	sf::Sprite* collisionSprite; // pointer to the collision sprite
    bool IsAlive(); //returns true if its character health is greater than zero and false if the characters health is less than zero
	virtual void Attack(); //method for when the character attacks
	virtual bool GetHit(); //method for when the character is hit by an obstical or another character
	virtual void Move(); //method for when the character moves from their current position
	virtual void Kill(); //method to destroy the characters object when killed inside of battle.



};// end of character class
#endif // !Character

