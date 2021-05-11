#pragma once
#include "HealthEntity.h"
#include "AcceleratedBullet.h"

class Enemy : public HealthEntity 
{
public:
	Enemy(sf::Vector2f SpawnPosition);

protected:
	sf::Vector2f bullet_spawn_offset_ { -8.8f, 24.f };
	sf::Clock _shootClock;
	sf::Clock _moveClock;
	bool _AttackOnCD = true;
	float _AttackCoolDown = 0.4f;
	float _MoveCoolDown = 10.f;
	bool _movedirection = false;
	bool _isOnScreen;
public:
	void MoveIntoScreen();
	void MoveUpDown();
	void Shoot();
	void Update();

};