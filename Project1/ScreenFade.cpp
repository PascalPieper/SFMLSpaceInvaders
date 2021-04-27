#include "ScreenFade.h"
ScreenFade::ScreenFade(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, bool FadeIn) : Entity (SpawnPosition)
{
	_color = color;
	_duration = FadeDuration;
	_clock.restart();
}



void ScreenFade::Fade()
{
}


void ScreenFade::Update()
{
	float result =_clock.getElapsedTime().asSeconds() / _duration;
	_color.a = (int)round(result * 255);
}


