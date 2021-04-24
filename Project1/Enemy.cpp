#include "Enemy.h"

Enemy::Enemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
}

void Enemy::MoveIntoScreen()
{
}

void Enemy::Shoot()
{
}

void Enemy::Update()
{
	this->EntitySprite.move(5 * pGameManager->GetDeltaTime(), 5 * pGameManager->GetDeltaTime());
}
