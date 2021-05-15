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

void GameManager::RegisterToIndex(unsigned int index, unsigned int id, std::shared_ptr<Entity> entity)
{
	CollisionListings[index].insert({id, entity});
}

void GameManager::UnRegisterFromIndex(unsigned index, unsigned int id)
{
	auto result = CollisionListings[index].find(id);
	CollisionListings[index].erase(result);
	//CollisionListings[index].erase(std::remove(CollisionListings[index].begin(), CollisionListings[index].end(), result), CollisionListings[index].end());
	//CollisionListings[index].erase(std::remove_if(CollisionListings[index].begin(), CollisionListings[index].end(), [](std::shared_ptr<Entity>) {return nullptr; }), CollisionListings[index].end());
	
}

void GameManager::RemoveEntity(unsigned ID)
{
	//std::remove(Entities.begin(), Entities.end(), ID), Entities.end()
	auto iterator = Entities.find(ID);
	Entities.erase(iterator);
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
	
	auto size = Entities.size();
	for (auto it = Entities.begin(); it != Entities.end(); ++it)
	{

		if (it->second != nullptr)
		{
			if (it->second->GetUpdateActiveState())
			{
				auto result = it->second;
				it->second->Update();
				result->collision_box_.setPosition(result->GetEntitySprite().getPosition() + result->collision_box_offset_);
			}
		}
		if (Entities.size() != size)
		{
			Update();
			break;
		}
	}
}


//NOT FULLY IMPLEMENTED
void GameManager::Draw(sf::RenderWindow &window)
{
	for (auto it = Entities.begin(); it != Entities.end(); ++it)
	{
		if (it->second->GetDrawActiveState())
		{
			window.draw(it->second->GetEntitySprite());
			if (ShowCollisionBoxes)
			{
				window.draw(it->second->collision_box_);
			}
		}

	}
	
	//for (int i = 0; i < Entities.size(); i++)
	//{
	//	if (Entities[i]->GetDrawActiveState())
	//	{
	//		window.draw(Entities[i]->GetEntitySprite());
	//		window.draw(Entities[i]->collision_box_);
	//	}
	//	
	//}
}

void GameManager::SetAllEntitiesActiveState(bool active)
{
		SetPaused(!active);
	
		for (auto it = Entities.begin(); it != Entities.end(); ++it)
		{

			if (it->second != nullptr)
			{
				it->second->SetUpdateActiveState(active);
			}
		}

}
