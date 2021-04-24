#pragma once
#include "MoveEntity.h"
class CollisionEntity : public MoveEntity 
{
public:
	CollisionEntity(sf::Vector2f SpawnPosition);
protected:
	unsigned int _collisionIndex = 0;

	//Rectangle Hitbox
public:
	sf::RectangleShape CollisionBox;

	//Setters
public:
	void SetCollisionIndex(unsigned int index) { _collisionIndex = index; }
	//Getters

public:
	unsigned int GetCollisionIndex() const { return _collisionIndex; }

};