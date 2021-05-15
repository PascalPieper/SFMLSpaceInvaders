#pragma once
#include <SFML/Graphics.hpp>

class SpriteEffects
{
	
protected:
	sf::Color original_color_;
	sf::Color target_color_;
	float delay_second_time = 5;
	sf::Sprite *p_sprite = nullptr;

public:
	SpriteEffects() {};
	SpriteEffects(sf::Sprite* const p_sprite, const float delay_second_time, const sf::Color target_color)
		: target_color_(target_color), delay_second_time(delay_second_time), p_sprite(p_sprite) {}
	
	void SetTargetSprite(sf::Sprite* p_sprite)
	{
		this->p_sprite = p_sprite;
		original_color_ = p_sprite->getColor();
	}

	void SetDelaySecondTime(float delay_second_time)
	{
		this->delay_second_time = delay_second_time;
	}

protected:
	sf::Clock effect_timer_;

public:
	void FlashSprite()
	{
		p_sprite->setColor(sf::Color::Red);
		effect_timer_.restart();
	}
	
void UpdateEffects() const
{
		if (effect_timer_.getElapsedTime().asSeconds() > delay_second_time)
		{
			p_sprite->setColor(original_color_);
		}
	}

	
};