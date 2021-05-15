#pragma once
#include "CollisionEntity.h"
class HealthEntity : public CollisionEntity
{
public:
	HealthEntity(sf::Vector2f SpawnPosition);
protected:

	unsigned int _maximumHealth;
	int _health;

	//Getters
public:
	unsigned int GetHealth() const { return _health; }

	//Setters
public:
	void SetHealth(unsigned int health) 
	{ health <= _maximumHealth ? _health = health : _health = _maximumHealth; }

	void SetMaximumHealth(unsigned int MaximumHealth) 
	{ _maximumHealth = MaximumHealth; }

	//Functions
public:
	virtual void OnDeath() {}
	virtual void TakeDamage(int Damage)
	{

		if (Damage > _health)
		{
			_health = 0;
			OnDeath();
		}
		else
		{
			_health -= Damage;
		}
			
	}

	virtual void Heal(unsigned int HealValue)
	{
		HealValue <= _maximumHealth ? _health += HealValue : _health = _maximumHealth;
	}
};