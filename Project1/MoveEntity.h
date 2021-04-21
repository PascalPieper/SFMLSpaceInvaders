#include "Entity.h"
class MoveEntity : public Entity
{
public:
	MoveEntity(std::string Path,
		unsigned int Layer,
		unsigned int CollisionIndex,
		sf::Vector2f SpawnPosition);
};