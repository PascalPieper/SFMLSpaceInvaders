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
	collision_box_offset_ = sf::Vector2f{ 0, 15.f };
	collision_box_.setSize(sf::Vector2f{ 41.0f,20.0f });
}

void PlayerCharacter::MoveUp()
{
	if (this->EntitySprite.getPosition().y > 0)
	{
		
		Move(0.f, -1.0f);
	}
	
}

void PlayerCharacter::MoveDown()
{
	std::cout << this->EntitySprite.getPosition().y;
	if (this->EntitySprite.getPosition().y < pGameManager->screen_height_ - this->EntitySprite.getTextureRect().height)
	{
		Move(0.f, 1.0f);
	}
	
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
	//pGameManager->CreateEntity<>()
}

void PlayerCharacter::Update()
{
	
	if (ImGui::SliderFloat("Hitbox player", &collision_box_size_y, -100, 100))
	{
		collision_box_.setSize(sf::Vector2f{ collision_box_size_x , collision_box_size_y });
	}
	//this->collision_box_.setPosition(this->EntitySprite.getPosition());
	if (CheckCollision(2))
	{
		std::cout << "Collision detected!";
	}
}
