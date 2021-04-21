#pragma once
#include "IUpdate.h"
#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
#include <iostream>

class Enemy : public sf::Transformable, public IUpdate
{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	Enemy();

protected:
	bool _direction;
	const std::string TEXTURE_PATH = "Assets/Sprites/SpaceShip.png";
	int _Health = 100;


public: 
	virtual void Update();
	virtual void move(float speed);
};