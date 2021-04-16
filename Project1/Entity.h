#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IUpdate.h"
namespace PP{
class Entity : public sf::Transformable, public IUpdate
{
public:
	Entity(); 
	~Entity();
protected:

	sf::Vector2f _position = sf::Vector2f{1.f, 1.f};

public:
	void SetTexture();
	void Update();
};
}