#include "AcceleratedBullet.h"

AcceleratedBullet::AcceleratedBullet(sf::Vector2f SpawnPosition) : Bullet (SpawnPosition)
{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/FireBullet2.png";

	TextureName = "BaseBullet";
	UniqueEntityName = "AcceleratedBullet";
	//_DrawLayer = 5;
	_MovementSpeed = 5;
	_AccelerationSpeed = 4;
	_AccelerationIncrease = 1;
	CollisionIndex = 2;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
	collision_box_.setFillColor(sf::Color::Red);
}

void AcceleratedBullet::FlyRight()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), 0);
	_AccelerationSpeed += _AccelerationIncrease;
}

void AcceleratedBullet::Update()
{
	//ImGui::SliderFloat("Basespeed", &_MovementSpeed, 0, 20);
	//ImGui::SliderFloat("AccelerationSpeed", &_AccelerationSpeed, 0, 20);
	//ImGui::SliderFloat("AccelerationIncrease", &_AccelerationIncrease, 0, 20);

	FlyRight();
	if (CheckCollision(0))
	{
		Destroy();
	}
}
