#pragma once
class IPlayerCharacter 
{
public:
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void Block() = 0;
	virtual void Dash() = 0;
	virtual void Jump() = 0;
	virtual void ChargeAttack() = 0;
};