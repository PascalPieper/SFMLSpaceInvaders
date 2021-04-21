#include "Entity.h"

Entity::Entity(sf::Vector2f SpawnPosition)
{
	_texture.loadFromFile(TEXTURE_PATH);
	_sprite.setTexture(_texture);
	_sprite.setPosition(SpawnPosition);
}

Entity::~Entity()
{
}

void Entity::SetID(unsigned int id)
{
	EntityID = id;
}

void Entity::SetSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

void Entity::SetCollisionIndex(unsigned int index)
{
	_CollisionIndex = index;
}

unsigned int Entity::GetCollisionIndex() const
{
	return _CollisionIndex;
}

void Entity::Update()
{
}

unsigned int Entity::GetID() const
{
	return EntityID;
}

void Entity::SetLayer(unsigned int layer)
{
	_Layer = layer;
}

unsigned int Entity::GetLayer() const
{
	return _Layer;
}
