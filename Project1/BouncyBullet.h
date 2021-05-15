#pragma once
#include "Bullet.h"
class BouncyBullet : public Bullet
{
public:
	BouncyBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi);
	void FlyRight() override;
	void Update() override;
protected:
	bool _direction;
public:
	bool IsDirection() const
	{
		return _direction;
	}

	void SetDirection(bool direction)
	{
		_direction = direction;
	}
};