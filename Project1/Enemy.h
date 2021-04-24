#pragma once
#include "HealthEntity.h"
class Enemy : public HealthEntity 
{
public:
	Enemy(sf::Vector2f SpawnPosition);

protected:
	bool _AttackOnCD = true;
	const float _AttackCoolDown = 0.4f;
public:
	void MoveIntoScreen();
	void Shoot();
	void Update();

};