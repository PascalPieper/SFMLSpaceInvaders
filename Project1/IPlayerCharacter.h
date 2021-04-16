#pragma once
class IPlayerCharacter 
{
public:
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	virtual void Block() = 0;
	virtual void Dash() = 0;
	virtual void Jump() = 0;
	virtual void ChargeAttack() = 0;
};