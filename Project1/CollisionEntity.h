#pragma once
#include "MoveEntity.h"


class CollisionEntity : public MoveEntity 
{
public:
	CollisionEntity(sf::Vector2f SpawnPosition);
public:
	std::vector<std::shared_ptr<Entity>>LastCollidedEntities;
	unsigned int CollisionIndex = 0;
	std::vector<unsigned int> CollisionTargetIndex;

	void RegisterEntity() override;
	void VerifyContinousCollisions();
	bool DetectCollision(unsigned int CollisionLayer);

	//Rectangle Hitbox
public:
	
	//Setters
public:
	void SetCollisionIndex(unsigned int index) { CollisionIndex = index; }
	//Getters

public:
	unsigned int GetCollisionIndex() const { return CollisionIndex; }

};