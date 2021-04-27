#pragma once
#include <SFML/Graphics.hpp>
#include "IUpdate.h"
#include <math.h>

class ScreenEffect : IUpdate
{
public:
	ScreenEffect();

protected:
	sf::Clock _clock;
	sf::Color _color = { 0,0,0,0 };

	float _duration;
public:
	sf::RectangleShape rect;
};