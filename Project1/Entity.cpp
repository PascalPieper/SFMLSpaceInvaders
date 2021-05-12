#include "Entity.h"
Entity::Entity(sf::Vector2f SpawnPosition)
{
	//EntitySprite.setTexture(texture);
	//EntitySprite.setPosition(SpawnPosition);
}

Entity::~Entity()
{
}


void Entity::Destroy()
{
	pGameManager->RemoveEntity(this->GetID());
}

void Entity::Update()
{
}
