#pragma once
class Entity;
#include <map>
#include "Entity.h"
#include "SaveGameManager.h"
class GameManager
{
public:
	GameManager();

public:
	mat_m::SaveGameManager* pSaveGameManager;
private:
	std::map<unsigned int, Entity*> Entities;
	unsigned int count = 0;
public:
	Entity* getEntity(unsigned int id);
	void CreateEntity(std::string Path, unsigned int Layer, unsigned int CollisionIndex, sf::Vector2f SpawnPosition);
};