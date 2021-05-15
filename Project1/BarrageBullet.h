#pragma once
#include "Bullet.h"
#include "PlayerCharacter.h"
class BarrageBullet : public Bullet
{
public:
	BarrageBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi, float time_limit);
	void FlyRight() override;
	void Update() override;
	sf::Clock direction_timer;
	void rise();
	void lower();
	float direction_time_limit;
	bool direction_;
};

