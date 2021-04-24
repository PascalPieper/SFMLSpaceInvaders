#include "Bullet.h"

Bullet::Bullet(sf::Vector2f SpawnPosition) : CollisionEntity(SpawnPosition)
{
	tag = BULLET;
	TEXTURE_PATH = "Assets/Sprites/Bullet.png";
	_DrawLayer = 5;
	_MovementSpeed = 1;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	_collisionIndex = 0;
	CollisionBox.setSize(sf::Vector2f{ 4.f,4.f });
}

void Bullet::Move()
{
	EntitySprite.move(-_MovementSpeed * _AccelerationSpeed * pGameManager->GetDeltaTime(), 0);
	_AccelerationSpeed += _AccelerationIncrease;
}

void Bullet::Update()
{
	if (isActive)
	{
		Move();
	}
}
