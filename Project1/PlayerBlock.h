#pragma once
#include "CollisionEntity.h"
class PlayerBlock : public CollisionEntity
{
public:
	PlayerBlock(sf::Vector2f spawn_position);

	void DisableHitBox();
	void EnableHitBox();
};

