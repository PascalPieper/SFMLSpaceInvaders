#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "IUpdate.h"
#include <string>
#include <iostream>
class GameManager;
class Entity : public sf::Transformable, public IUpdate
{
public:
	Entity(sf::Vector2f SpawnPosition);
	~Entity();

protected:
	unsigned int EntityID = 0;

	unsigned int _Layer = 0;
	unsigned int _CollisionIndex = 0;

	const std::string TEXTURE_PATH = "Assets/Images/rainerSmall.jpg";
	std::string FileName;

	sf::Texture _texture;

public:
	enum EntityTag { PLAYER = 0, ENEMY = 1, NPC = 2, BULLET = 3, PLATFORM = 4, BACKGROUND = 5, HITBOX = 6 };
	EntityTag tag = ENEMY;
	sf::Sprite _sprite;
	GameManager* pGameManager;
public:
	void SetID(unsigned int id);
	unsigned int GetID() const;

	void SetLayer (unsigned int layer);
	unsigned int GetLayer() const;

	void SetSprite(sf::Sprite sprite);

	void SetCollisionIndex(unsigned int index);
	unsigned int GetCollisionIndex() const;

	void Update();
};