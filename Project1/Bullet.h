#pragma once
#include "CollisionEntity.h"
class GameManager;
class Bullet : public CollisionEntity
{
public:
	Bullet(sf::Vector2f SpawnPosition);

	virtual void Move();
	virtual void Update();
};