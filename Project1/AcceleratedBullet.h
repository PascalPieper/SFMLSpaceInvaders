#pragma once
#include "Bullet.h"
#include "PlayerCharacter.h"
class AcceleratedBullet : public Bullet
{
public:
	AcceleratedBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi);
	void FlyRight() override;
	void Update() override;
};