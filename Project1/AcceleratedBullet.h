#pragma once
#include "Bullet.h"
class AcceleratedBullet : public Bullet
{
public:
	AcceleratedBullet(sf::Vector2f SpawnPosition);
	void FlyRight() override;
	void Update() override;
};