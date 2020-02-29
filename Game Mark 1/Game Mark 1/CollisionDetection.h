#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H
#include "Collision.hpp"

class CollisionDetection {
public:
	bool EnemyCollideWithPlayer();
	bool PlayerCollideWithEnemy();
	bool PlayerCollideWithWall();
	bool EnemyCollideWithWall();
	bool PlayerCollideWithPowerUp();
	bool onPickupObject();
};


#endif // !COLLISION_DETECTION_H
