/*
** Last Author: Jordan
** Date Modified: 29/11/19
** Version: 0.1
** Change Log:
*** -------- <29/11/19>
***	<Jordan> collect () method to effect player stats when pickedup
***	<Jordan> spawn()  for to spawn Power up and set its type. Then set powerUpSprite poistion.
***	<Jordan> collected() If the player collects the powerUp we set it to false
*** --------- End of Changes
*/

#include "PowerUp.H"
#include "Player.h"
PowerUp::PowerUp()
{
	m_Spawned = false;
	sm = new SpriteManager();
}

//Places a power up somewhere in a level of different types.
void PowerUp::spawn(int Startx , int Starty,int type)
{
	m_Spawned = true;
	m_typeID = type;
	switch (m_typeID)
	{
		case 1: PowerUpSprite = sm->GetSprite("Textures/HeartPickup.png");
			PowerUpSprite->setScale(2, 2);
			break;
		case 2: PowerUpSprite = sm->GetSprite("Textures/laturn2.png");
			PowerUpSprite->setScale(.09, .09);
			break;
		default:
			break;
	}
	m_Spawned = true;

	PowerUpSprite->setPosition(Startx, Starty);
	//PowerUpSprite->setScale(.5,.5);
}

/*
	Uses collison system to check if the player has collided with a pickup 
	check the powerUp type. Based on that either give player health or inrease visibility 
*/
void PowerUp::collect(Player* p1)
{

	if (Collision::PixelPerfectTest(*p1->characterSprite, *PowerUpSprite))// Has the player touched the powerUp?
	{
		/*
			1 is for health pickup
			2 is for visibility
		*/
		switch (m_typeID)
		{
			case 1: p1->m_health += 2.5; // 
				break;
			case 2: p1->visibililty += 1;
				p1->visibility.active = true;
				break;
			case 3: //Increase attack
				break;
			case 4: //Temporary invincibility
				break;
			default: cout << "This is not a valid option" << endl;
				break;
		}//End of switch.
		collected();
	}
}

/*
	Once the player has collected the power up we set m_Spawned to false to show to delete it.
*/
void PowerUp::collected()
{
	m_Spawned = false;
}

