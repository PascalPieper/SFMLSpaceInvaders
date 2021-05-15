#pragma once
#include "HealthEntity.h"
#include "AcceleratedBullet.h"
#include "BouncyBullet.h"

class Enemy : public HealthEntity 
{
public:
	Enemy(sf::Vector2f SpawnPosition);

protected:
	sf::Vector2f bullet_spawn_offset_ { -8.8f, 24.f };
	sf::Clock _shootClock;
	sf::Clock _moveClock;
	bool _AttackOnCD = true;
	float _AttackCoolDown = 1.f;
	float _MoveCoolDown = 10.f;
	bool _movedirection = false;
	bool _isOnScreen;
	SpriteEffects se_;
	void OnDeath() override;
	typedef void (Enemy::* fptr)();
	fptr func;
	
public:
	void Start() override;
	void MoveIntoScreen();
	void MoveUpDown();
	void Shoot();
	void ShootAccelerated();
	void ShootBouncing();
	void Update();
	void MoveToScreenTop();

};