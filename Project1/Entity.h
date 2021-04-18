#pragma once
#include <Thor/Resources.hpp>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
#include "IUpdate.h"

namespace mat
{
class Entity : public sf::Transformable, public IUpdate
{
public:
	Entity(GameManager* gm);
	~Entity();
protected:
	GameManager* pgm;
	const std::string TEXTURE_PATH;
	thor::ResourceLoader<sf::Texture> Texture = thor::Resources::fromFile<sf::Texture>("image.jpg");
	sf::Vector2f _position;

public:
	void SetTexture();
	void Update();
};
}