#pragma once
#include "MoveEntity.h"
class CollisionEntity : public MoveEntity 
{
public:
	CollisionEntity(sf::Vector2f SpawnPosition);
protected:
	unsigned int _CollisionIndex = 0;

	//Rectangle Hitbox
public:
	sf::RectangleShape CollisionBox;

	//Setters
public:
	void SetCollisionIndex(unsigned int index) { _CollisionIndex = index; }
	//Getters

public:
	unsigned int GetCollisionIndex() const { return _CollisionIndex; }

};