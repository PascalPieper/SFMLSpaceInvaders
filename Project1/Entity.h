#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "GameManager.h"
#include "IUpdate.h"
#include "FilePath.h"
class Entity : public IUpdate
{
public:
	Entity(GameManager* pgm);

protected:
	

public:
	const std::string TEXTURE_PATH = "Assets\\Textures\\MissingTexture.jpg";
	unsigned int EntityID;
	sf::Sprite EntitySprite;

	// Inherited via IUpdate
	virtual void Update() override;
};