#include "MoveEntity.h"

MoveEntity::MoveEntity (sf::Vector2f SpawnPosition) : Entity (SpawnPosition)
{

}

void MoveEntity::MoveToTarget(Entity target)
{
	//target.EntitySprite.getPosition();
}

void MoveEntity::Move(float x, float y)
{
	this->EntitySprite.move(x, y);
	this->collision_box_.setPosition(EntitySprite.getPosition());
}
