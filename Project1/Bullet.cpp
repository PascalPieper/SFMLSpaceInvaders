#include "Bullet.h"

Bullet::Bullet(sf::Vector2f SpawnPosition) : CollisionEntity(SpawnPosition)
{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/Bullet.png";
	TextureName = "BaseBullet";
	//_DrawLayer = 5;
	_MovementSpeed = 5;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 0;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
}

void Bullet::FlyRight()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), 0);
	_AccelerationSpeed += _AccelerationIncrease;
}

void Bullet::Update()
{
		FlyRight();
}
