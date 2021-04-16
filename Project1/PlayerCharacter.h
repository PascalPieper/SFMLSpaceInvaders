#pragma once
#include "IPlayerCharacter.h"
#include <iostream>
class PlayerCharacter : public IPlayerCharacter
{
public:
	PlayerCharacter();
	// Inherited via IPlayerCharacter
	virtual void MoveLeft() override;
	virtual void MoveRight() override;
	virtual void Block() override;
	virtual void Dash() override;
	virtual void Jump() override;
	virtual void ChargeAttack() override;
};