#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "IUpdate.h"
#include <string>
#include <iostream>
#include "EntityEnums.h"
#include <SFML/OpenGL.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <charconv>
#include <algorithm>
#include <vector>

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
	bool _isRendered = true;
	bool _isActive = true;

	//The Unique ID that is bestowed upon every Entity upon creation that can be
	//used to find the Object
	unsigned int UniqueEntityID = 0;



	//Predifned tag that the Entity receives
	Tag::EntityTag tag = Tag::ENEMY;
	sf::Texture EntityTexture;
	sf::Sprite EntitySprite;

	//The directiory path on the harddrive to the texture that is applied to the Rect
	std::string TEXTURE_PATH = "Assets/Images/rainerSmall.jpg";
	std::string TextureName = "TestName";

	std::string UniqueEntityName = "TestName";

public:
	//The drawing layer that decides if an Entity is rendered behind or in front of other
//Layer objects
	unsigned int _DrawLayer = 0;
	//Register to different Managers after being created by the GameManager
	virtual void RegisterEntity() {};

	sf::RectangleShape collision_box_;
	float collision_box_size_x;
	float collision_box_size_y;
	sf::Vector2f collision_box_offset_;
	
	void SetID(const unsigned int id) { UniqueEntityID = id; }
	unsigned int GetID() const { return UniqueEntityID; }
	void SetUpdateActiveState(bool state) { _isActive = state; }
	void SetRenderActiveState(bool state) { _isRendered = state; }
	void SetActiveAndRendered(bool state) {	_isActive = state; _isRendered = state;}
	bool GetUpdateActiveState() const { return _isActive; }
	bool GetRenderActiveState() const { return _isRendered; }
	void SetDrawLayer(unsigned int layer) {_DrawLayer = layer;}
	unsigned int GetDrawLayer() const {};

	void SetSprite(sf::Sprite sprite) { EntitySprite = sprite;}
	sf::Sprite& GetEntitySprite() { return EntitySprite; }

	std::string getTextureName() const { return TextureName; }
	std::string getTexturePath() const { return TEXTURE_PATH; }

	void SetPosition(sf::Vector2f position) { EntitySprite.setPosition(position); }
	virtual void Update();

};