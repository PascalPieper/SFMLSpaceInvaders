#include "EntityManager.h"

mat_m::EntityManager::EntityManager()
{
}


unsigned int mat_m::EntityManager::AssignEntityID()
{
	EntityCount++;
	return EntityCount;
}

void mat_m::EntityManager::AddToEntities(int *id, Entity &entity)
{
	Entities.insert({ *id, &entity });
}

void mat_m::EntityManager::AcquireTexture(std::string& FilePath)
{
	
}

Entity* mat_m::EntityManager::CreateNewEntity()
{
	Entity *ent = new Entity(pgm);
	ent->EntityID = AssignEntityID();
	AddToEntities(ent->EntityID, *ent);

	sf::Texture& texture = PrepareTexture(ent);
	ent->EntitySprite.setTexture(texture);
	return ent;
}

sf::Texture & mat_m::EntityManager::PrepareTexture(Entity* pEntity)
{
	holder.acquire(pEntity->TEXTURE_PATH, thor::Resources::fromFile<sf::Texture>(pEntity->TEXTURE_PATH));
	return holder[pEntity->TEXTURE_PATH];
}


void mat_m::EntityManager::Update()
{
	for (int i = 0; i < Entities.size; i++)
	{
		Entities[i].Update();
	}
}
