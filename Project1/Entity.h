#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "IUpdate.h"
#include <string>
#include <iostream>
#include "EntityEnums.h"

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
	bool _isActive = true;
	//The Unique ID that is bestowed upon every Entity upon creation that can be
	//used to find the Object
	unsigned int _EntityID = 0;

	//The drawing layer that decides if an Entity is rendered behind or in front of other
	//Layer objects
	//unsigned int _DrawLayer = 0;

	//DrawLayer _DrawLayer = BACKGROUND_01;



	//sf::Transform &ParentPosition;

	//Predifned tag that the Entity receives
	Tag::EntityTag tag = Tag::ENEMY;
	sf::Texture EntityTexture;
	sf::Sprite EntitySprite;

	//The directiory path on the harddrive to the texture that is applied to the Rect
	std::string TEXTURE_PATH = "Assets/Images/rainerSmall.jpg";
	std::string TextureName = "TestName";

public:
	void SetID(unsigned int id) { _EntityID = id; }
	unsigned int GetID() const { return _EntityID; }
	void SetActive(bool state) { _isActive = state; }
	bool GetActiveState() { return _isActive; }
	//void SetDrawLayer(unsigned int layer) {_DrawLayer = layer;}
	//unsigned int GetDrawLayer() const {};

	void SetSprite(sf::Sprite sprite) { EntitySprite = sprite;}
	sf::Sprite& GetEntitySprite() { return EntitySprite; }
	std::string getTextureName() { return TextureName; }
	std::string getTexturePath() { return TEXTURE_PATH; }
	void SetPosition(sf::Vector2f position) { EntitySprite.setPosition(position); }
	virtual void Update();
};