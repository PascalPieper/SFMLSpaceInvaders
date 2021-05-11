#pragma once
#include "IPlayerCharacter.h"
#include "HealthEntity.h"
#include <iostream>
class PlayerCharacter : public HealthEntity, IPlayerCharacter
{
public:
	PlayerCharacter(sf::Vector2f spawn_position);
	// Inherited via IPlayerCharacter
	virtual void MoveUp() override;
	virtual void MoveDown() override;
	virtual void Block() override;
	virtual void Dash() override;
	virtual void Jump() override;
	virtual void ChargeAttack() override;
	void Update() override;
};