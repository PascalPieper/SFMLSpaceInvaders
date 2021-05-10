#pragma once
#include "Bullet.h"
class BouncyBullet : public Bullet
{
public:
	BouncyBullet(sf::Vector2f SpawnPosition);
	void Move() override;
	void Update() override;
protected:
	bool _direction;
};