#include "MoveEntity.h"

MoveEntity::MoveEntity
(
	std::string Path, 
	unsigned int Layer, 
	unsigned int CollisionIndex,
	sf::Vector2f SpawnPosition
)
	: Entity(Path, Layer, CollisionIndex, SpawnPosition)
{

}
