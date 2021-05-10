#pragma once
#include <SFML/Graphics.hpp>
#include "IUpdate.h"
#include <math.h>
#include "EntityEnums.h"

class Overlay : IUpdate
{
public:
	Overlay(sf::Vector2i offset, Alignment::Alignment alignment);
protected:
	sf::Clock _clock;
	sf::Color _color = { 0,0,0,0 };
	float _duration;

public:
	void Update();
	sf::RectangleShape rect;
};