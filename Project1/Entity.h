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

	//GameManager Reference Pointer that is used to access all other
	//Engine specific Manager classes
	GameManager* pGameManager;
protected:
	//The Unique ID that is bestowed upon every Entity upon creation that can be
	//used to find the Object
	unsigned int _EntityID = 0;

	//The drawing layer that decides if an Entity is rendered behind or in front of other
	//Layer objects
	unsigned int _DrawLayer = 0;

public:
	bool isActive = true;

	//Tagging system that makes finding certain types of Entities easier inside the GameManager
	enum EntityTag { PLAYER = 0, ENEMY = 1, NPC = 2, BULLET = 3, PLATFORM = 4, BACKGROUND = 5, HITBOX = 6 };

	//sf::Transform &ParentPosition;

	//Predifned tag that the Entity receives
	EntityTag tag = ENEMY;
	sf::Texture EntityTexture;
	sf::Sprite EntitySprite;

	//The directiory path on the harddrive to the texture that is applied to the Rect
	std::string TEXTURE_PATH = "Assets/Images/rainerSmall.jpg";
	std::string TextureName = "TestName";

public:
	void SetID(unsigned int id) { _EntityID = id; }
	unsigned int GetID() const { return _EntityID; }

	void SetDrawLayer(unsigned int layer) {_DrawLayer = layer;}
	unsigned int GetDrawLayer() const {};

	void SetSprite(sf::Sprite sprite) { EntitySprite = sprite;}

	virtual void Update();
};