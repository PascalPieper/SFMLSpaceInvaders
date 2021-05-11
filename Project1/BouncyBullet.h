#pragma once
#include "Bullet.h"
class BouncyBullet : public Bullet
{
public:
	BouncyBullet(sf::Vector2f SpawnPosition);
	void FlyRight() override;
	void Update() override;
protected:
	bool _direction;
};