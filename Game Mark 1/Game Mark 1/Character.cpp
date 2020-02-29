#include "Character.h"

Character::Character() {
	//Set the character variables to default

}
Character::~Character()
{
	delete[] characterSprite;
};

bool Character::IsAlive() {
	//takes in characters health variable
	//checks if the character health variable is less than or equal to zero
	//if character health is equal to zero
	//if it is less than or equal to zero return false
	//if it is not less thn or equal to zero return true
	// if it returns false goes into the Objects Kill Function
	if (m_health < 0)
	{
		return true;
	}

	return false;
}

void Character::Attack() {
	//manipulate the characters sprite go into animation that simulate attacking
	//goes into the enemy object gets return either true or false
	//if true takes a bit of health out of the enemy object health variable
	//if the checks the enemy objects health variable less than or equal to zero through the objects IsAlive() function
}

bool Character::GetHit() {
	//After the character has attacked an enemy checks if the character has gotten hit by an opposing object 
	//if character is hit checks how much health is taking from the characters object health variable
	//then it goes into the isAlive function and returns into true or false
	return true;
}

void Character::Move() {
	//Manipulate the character sprite to move into differenct direction
}

void Character::Kill() {
	//if the character isAlive returns false
	//takes the object of the board
	//Destroys object
}
