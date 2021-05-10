#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <math.h>
#include <functional>
#include <vector>
class ScreenFade
{
public:
	ScreenFade(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, sf::Vector2f size);
	typedef void (*OnFadeFinished)();
	OnFadeFinished onFade;
	void Update();

protected:
	
	sf::Clock _clock;
	sf::Color _color = { 0,0,0,0 };

	float _duration;
public:
	sf::RectangleShape rect;
};