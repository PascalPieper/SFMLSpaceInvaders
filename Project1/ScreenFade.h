#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <math.h>
class ScreenFade
{
public:
	ScreenFade(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, sf::Vector2f size);
	void Update();

protected:
	
	sf::Clock _clock;
	sf::Color _color = { 0,0,0,0 };

	float _duration;
public:
	sf::RectangleShape rect;
};