#pragma once
#include <SFML/Graphics.hpp>
class IPlayerCharacter 
{
public:
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	virtual void Block() = 0;
	virtual void Dash() = 0;
	virtual void Jump() = 0;
	virtual void ChargeAttack() = 0;
	virtual sf::Vector2f GetPositon() = 0;
};