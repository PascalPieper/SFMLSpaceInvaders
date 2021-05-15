#include "PlayerBlock.h"

PlayerBlock::PlayerBlock(const sf::Vector2f spawn_position) : CollisionEntity(spawn_position)
{
	tag = Tag::ENEMY;
	is_animated_ = false;
	TEXTURE_PATH = "Assets/Sprites/Anek_shield.png";
	TextureName = "Anek_Block";
	//_DrawLayer = 5;
	_MovementSpeed = 80;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 1;
	collision_box_offset_ = sf::Vector2f{ 2.5, 0.f };
	collision_box_.setSize(sf::Vector2f{ 8.0f,52.0f });
	texture_animation_offset = sf::IntRect(0, 0, 11, 52);
	//animation_sheet_width_ = 41;
}

void PlayerBlock::DisableHitBox()
{
	collision_box_.setSize(sf::Vector2f{ 0,0 });
}

void PlayerBlock::EnableHitBox()
{
	collision_box_.setSize(sf::Vector2f{ 8.0f,52.0f });
}
