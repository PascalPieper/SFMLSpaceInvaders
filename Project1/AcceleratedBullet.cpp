#include "AcceleratedBullet.h"

AcceleratedBullet::AcceleratedBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi) : Bullet (SpawnPosition)
{
	texture_animation_offset = sf::IntRect(0, 0, 21, 12);
	animation_sheet_width_ = 84;
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/Fireball_final.png";
	TextureName = "BaseBullet";
	UniqueEntityName = "AcceleratedBullet";
	//_DrawLayer = 5;
	_MovementSpeed = move_speed;
	angle_multi_ = angle_multi;
	_AccelerationSpeed = 4;
	_AccelerationIncrease = 1;
	CollisionIndex = 3;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
	collision_box_.setFillColor(sf::Color::Red);

	collision_box_.setSize(sf::Vector2f{ 21.0f,12.0f });
}

void AcceleratedBullet::FlyRight()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), angle_multi_ * 1 * pGameManager->GetDeltaTime());
	_AccelerationSpeed += _AccelerationIncrease;
}

void AcceleratedBullet::Update()
{
	//ImGui::SliderFloat("Basespeed", &_MovementSpeed, 0, 20);
	//ImGui::SliderFloat("AccelerationSpeed", &_AccelerationSpeed, 0, 20);
	//ImGui::SliderFloat("AccelerationIncrease", &_AccelerationIncrease, 0, 20);
	
	FlyRight();
	//Destroy();
	if (CheckCollision(1))
	{
		Destroy();
		return;
	}
	if (CheckCollision(0))
	{
		pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->TakeDamage(9);
		Destroy();
		return;
	}

	OutOfBoundsCheck();
	ProgressAnimation();
}
