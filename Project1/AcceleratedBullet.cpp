#include "AcceleratedBullet.h"

AcceleratedBullet::AcceleratedBullet(sf::Vector2f SpawnPosition) : Bullet (SpawnPosition)
{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/Bullet.png";
	TextureName = "BaseBullet";
	//_DrawLayer = 5;
	_MovementSpeed = 2;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 1.f;
	_collisionIndex = 0;
	CollisionBox.setSize(sf::Vector2f{ 4.f,4.f });
}

void AcceleratedBullet::Move()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), 0);
	_AccelerationSpeed += _AccelerationIncrease;
}

void AcceleratedBullet::Update()
{
}
