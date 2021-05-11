#pragma once
#include "IManager.h"
#include <SFML/Graphics.hpp>
class PlayerGui : public IManager
{
public:
	sf::RectangleShape hp_back_;
	sf::RectangleShape stamina_back_;
};

