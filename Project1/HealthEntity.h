#pragma once
#include "CollisionEntity.h"
class HealthEntity : public CollisionEntity
{
public:
	HealthEntity(sf::Vector2f SpawnPosition);
protected:

	unsigned int _maximumHealth;
	unsigned int _health;

	//Getters
public:
	unsigned int GetHealth() { return _health; }

	//Setters
public:
	void SetHealth(unsigned int health) 
	{ health <= _maximumHealth ? _health = health : _health = _maximumHealth; }

	void SetMaximumHealth(unsigned int MaximumHealth) 
	{ _maximumHealth = MaximumHealth; }

	//Functions
public:

	void TakeDamage(unsigned int Damage)
	{
		Damage > _health ? _health = 0 : _health -= Damage;
	}

	void Heal(unsigned int HealValue)
	{
		HealValue <= _maximumHealth ? _health += HealValue : _health = _maximumHealth;
	}
};