#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <Thor/Resources.hpp>
#include "Entity.h"



namespace mat_m 
{
class EntityManager 
{

public:
	EntityManager();

private:
	
	//Holder for all textures
	

	//Id assignment value for every asset
	//FIX ME: Is never reset, thus can only support around 60k assets. 
	//for longtime support should be reset after scene load



public:
	GameManager * pgm = nullptr;
	std::map<unsigned int*, Entity*> Entities;

	unsigned int EntityCount;

	unsigned int AssignEntityID();
	void AddToEntities(unsigned int *id, Entity *entity);

	thor::ResourceHolder<sf::Texture, std::string> holder;
	void AcquireTexture(std::string& FilePath);

	Entity* CreateNewEntity();
	sf::Texture& PrepareTexture(Entity* pEntity);
	void Update();
};
}