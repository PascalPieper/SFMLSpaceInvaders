#pragma once
#include "HealthEntity.h"
#include "AcceleratedBullet.h"
#include "BouncyBullet.h"
class SnakeEnemy : public HealthEntity
{
public:
	SnakeEnemy(sf::Vector2f SpawnPosition);
protected:
	sf::Vector2f bullet_spawn_offset_{ -8.8f, 24.f };
	sf::Clock _shootClock;
	sf::Clock _moveClock;
	bool _AttackOnCD = true;
	float _AttackCoolDown = 2.f;
	float _MoveCoolDown = 10.f;
	bool _movedirection = false;
	bool _isOnScreen;
	void OnDeath() override;
	SpriteEffects se_;
	typedef void (SnakeEnemy::* fptr)();
	fptr func;

public:
	void Start() override;
	void MoveIntoScreen();
	void MoveUpDown();
	void Shoot();
	void ShootAccelerated();
	void ShootBouncing();
	void Update() override;
	void MoveToScreenTop();
};

