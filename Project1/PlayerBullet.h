#pragma once
#include "Bullet.h"
class PlayerBullet : public Bullet
{
public:
	PlayerBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi);
	void FlyRight() override;
	void FlyLeft();
	void Update() override;
protected:
	bool _direction{};
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

