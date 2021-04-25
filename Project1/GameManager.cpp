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
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->Update();
	}
}

//NOT FULLY IMPLEMENTED
void GameManager::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < Entities.size(); i++)
	{
		window.draw(Entities[i]->EntitySprite);
	}
}
