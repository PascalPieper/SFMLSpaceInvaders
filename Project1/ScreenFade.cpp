#include "ScreenFade.h"
ScreenFade::ScreenFade(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, sf::Vector2f size)
{
	_color = color;
	_duration = FadeDuration;
	_clock.restart();
	rect.setFillColor(color);
	rect.setSize(size);
}


void ScreenFade::Update()
{
	if (_clock.getElapsedTime().asSeconds() < _duration)
	{
	float result =_clock.getElapsedTime().asSeconds() / _duration;
	_color.a = (int)round(result * 255);
	rect.setFillColor(_color);
	}
	else
	{
		return;
	}
	/*
	if (_clock.getElapsedTime().asSeconds() > 2)
	{
		sf::Color color = { 0,0,0,255 };
		rect.setFillColor(color);
	}
	*/
	//std::cout << _clock.getElapsedTime().asSeconds() << std::endl;
}


