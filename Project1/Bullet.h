#pragma once
#include "CollisionEntity.h"
class GameManager;
class Bullet : public CollisionEntity
{
public:
	Bullet(sf::Vector2f SpawnPosition);

	virtual void FlyRight();
	virtual void Update();
	virtual void OutOfBoundsCheck();
protected:
	float angle_multi_;
};