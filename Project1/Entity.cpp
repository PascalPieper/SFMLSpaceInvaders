#include "Entity.h"

Entity::Entity(sf::Vector2f SpawnPosition)
{
	_texture.loadFromFile(TEXTURE_PATH);
	EntitySprite.setTexture(_texture);
	EntitySprite.setPosition(SpawnPosition);
}

Entity::~Entity()
{
}

void Entity::Update()
{
}
