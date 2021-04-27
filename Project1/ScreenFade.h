#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <math.h>
class ScreenFade : public Entity
{
public:
	ScreenFade(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, bool FadeIn);
	void Update() override;

protected:
	sf::Clock _clock;
	void Fade();
	sf::Color _color = { 0,0,0,0 };
	float _duration;
};