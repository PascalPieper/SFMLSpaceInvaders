#include "GameManager.h"
class Entity;
GameManager::GameManager() 
	: _deltaTime(0)
{
	
}

void GameManager::RefreshDeltatime()
{

	_deltaTime = clock.restart().asSeconds();
}

void GameManager::SortByDrawIndex()
{

}

void GameManager::RegisterToIndex(unsigned int index, std::shared_ptr<Entity> entity)
{
	CollisionListings[index].push_back(entity);
}

void GameManager::UnRegisterFromIndex(unsigned index, unsigned int id)
{
	auto result = Entities.find(id)->second;
	CollisionListings[index].erase(std::remove(CollisionListings[index].begin(), CollisionListings[index].end(), result), CollisionListings[index].end());
	//CollisionListings[index].erase(std::remove_if(CollisionListings[index].begin(), CollisionListings[index].end(), [](std::shared_ptr<Entity>) {return nullptr; }), CollisionListings[index].end());
	
}

void GameManager::RemoveEntity(unsigned ID)
{
	Entities.erase(entity_ids_in_scene_[ID]);
	entity_ids_in_scene_.erase(std::remove(entity_ids_in_scene_.begin(), entity_ids_in_scene_.end(), ID), entity_ids_in_scene_.end());
	

}

std::shared_ptr<Entity> GameManager::getEntity(unsigned int id)
{
	return Entities.find(id)->second;
}
/*
//Create a new Entity on the heap that can be accessed through the Entities vector
//Returns the reference to the newly created Entity
std::shared_ptr<Entity> GameManager::CreateEntity(sf::Vector2f SpawnPosition)
{
	std::shared_ptr<Entity> NewEntity = std::make_shared<Entity>(SpawnPosition);
	//Supply Entity with reference to the Game Manager
	NewEntity->pGameManager = this;

	//Load or Reference the texture from the Assetmanager
	NewEntity->EntitySprite.setTexture(pAssetManager->LoadTexture(NewEntity->TextureName, NewEntity->TEXTURE_PATH));

	//Share ownership to the Entity to all Entity vector, which will be used for finding and filtering
	Entities.insert({ count, NewEntity });
	count++;
	return NewEntity;
}

std::shared_ptr<Entity> GameManager::CreateBullet(sf::Vector2f SpawnPosition)
{
	std::shared_ptr<Bullet> NewEntity = std::make_shared<Bullet>(SpawnPosition);
	//Supply Entity with reference to the Game Manager
	NewEntity->pGameManager = this;

	//Load or Reference the texture from the Assetmanager
	NewEntity->EntitySprite.setTexture(pAssetManager->LoadTexture(NewEntity->TextureName, NewEntity->TEXTURE_PATH));

	//Share ownership to the Entity to all Entity vector, which will be used for finding and filtering
	Entities.insert({ count, NewEntity });
	count++;
	return NewEntity;
}
*/
//Updates all Entities enlisted in the entities vector
void GameManager::Update()
{
	for (int i = 0; i < entity_ids_in_scene_.size(); i++)
	{
		for (auto it = Entities.cbegin(), next_it = it; it != Entities.cend(); it = next_it)
		{
			++next_it;
			if (it->second == nullptr)
			{
				Entities.erase(it);
			}
		}
		auto ptr = Entities[entity_ids_in_scene_[i]];
		if (ptr != nullptr)
		{
		if (ptr->GetUpdateActiveState())
		{
			ptr->collision_box_.setPosition(Entities[i]->GetEntitySprite().getPosition() + Entities[i]->collision_box_offset_);
			ptr->Update();
			
		}

		}
	}
}


//NOT FULLY IMPLEMENTED
void GameManager::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < Entities.size(); i++)
	{
		if (Entities[i]->GetRenderActiveState())
		{
			window.draw(Entities[i]->GetEntitySprite());
			window.draw(Entities[i]->collision_box_);
		}
		
	}
}
