#pragma once
#include "CollisionEntity.h"
class HealthEntity : public CollisionEntity
{
public:
	HealthEntity(sf::Vector2f SpawnPosition);
protected:

	unsigned int MaximumHealth;
	unsigned int _Health;

	//Getters
public:
	unsigned int GetHealth() { return _Health; }

	//Setters
public:
	void SetHealth(unsigned int health) {}
	void TakeDamage(unsigned int Damage) { Damage > _Health ? _Health = 0 : _Health -= Damage; }
	void Heal(unsigned int HealValue) {}
};