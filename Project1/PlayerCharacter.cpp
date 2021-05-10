#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(sf::Vector2f spawn_position) : HealthEntity(spawn_position)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Anek.png";
	TextureName = "Anek";
	//_DrawLayer = 5;
	_MovementSpeed = 80;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 0;
	//CollisionBox.setSize(sf::Vector2f{ 4.f,4.f });
}

void PlayerCharacter::MoveLeft()
{
	//std::cout << "Moving left!";
}

void PlayerCharacter::MoveRight()
{
}

void PlayerCharacter::Block()
{
}

void PlayerCharacter::Dash()
{
}

void PlayerCharacter::Jump()
{
}

void PlayerCharacter::ChargeAttack()
{
}
