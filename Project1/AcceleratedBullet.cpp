#include "AcceleratedBullet.h"

AcceleratedBullet::AcceleratedBullet(sf::Vector2f SpawnPosition) : Bullet (SpawnPosition)
{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/Bullet.png";

	TextureName = "BaseBullet";
	UniqueEntityName = "AcceleratedBullet";
	//_DrawLayer = 5;
	_MovementSpeed;
	_AccelerationSpeed;
	_AccelerationIncrease;
	CollisionIndex = 2;
	//CollisionBox.s(sf::Vector2f{ 4.f,4.f });
}

void AcceleratedBullet::Move()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), 0);
	_AccelerationSpeed += _AccelerationIncrease;
}

void AcceleratedBullet::Update()
{
	ImGui::SliderFloat("Basespeed", &_MovementSpeed, 0, 20);
	ImGui::SliderFloat("AccelerationSpeed", &_AccelerationSpeed, 0, 20);
	ImGui::SliderFloat("AccelerationIncrease", &_AccelerationIncrease, 0, 20);
	Move();
}
