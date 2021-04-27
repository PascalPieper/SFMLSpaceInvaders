#pragma once
#include "Bullet.h"
class AcceleratedBullet : public Bullet
{
public:
	AcceleratedBullet(sf::Vector2f SpawnPosition);
	void Move() override;
	void Update() override;
};