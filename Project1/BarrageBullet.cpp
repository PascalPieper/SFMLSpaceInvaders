#include "BarrageBullet.h"

#include "PlayerCharacter.h"

BarrageBullet::BarrageBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi, float time_limit) : Bullet(SpawnPosition)
{
	tag = Tag::BULLET;
	is_animated_ = false;
	TEXTURE_PATH = "Assets/Sprites/BarrageBullet.png";
	TextureName = "EBarrageBullet";
	//_DrawLayer = 5;
	_MovementSpeed = move_speed;
	_AccelerationSpeed = 0.0f;
	_AccelerationIncrease = 0.00f;
	CollisionIndex = 3;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
	angle_multi_ = angle_multi;
	direction_time_limit = time_limit;
	direction_ = true;
}


void BarrageBullet::FlyRight()
{
	
	if (direction_timer.getElapsedTime().asSeconds() < direction_time_limit)
	{
		rise();
	}
	if (direction_timer.getElapsedTime().asSeconds() > direction_time_limit)
	{
		lower();
	}
	if (direction_timer.getElapsedTime().asSeconds() > direction_time_limit * 2)
	{
		direction_timer.restart();
	}
	//if (direction_timer.getElapsedTime().asSeconds() > 1.5f)
	//{
	//	direction_timer.restart();
	//}
	EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), -_MovementSpeed * pGameManager->GetDeltaTime() * angle_multi_);

}

void BarrageBullet::Update()
{
	FlyRight();
	OutOfBoundsCheck();
	if (CheckCollision(1))
	{
		Destroy();
		return;
	}
	if (CheckCollision(0))
	{
		pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->TakeDamage(2);
		Destroy();
	}
}

void BarrageBullet::rise()
{
	if (angle_multi_ > 0)
	{
		angle_multi_ = 0;
	}
	angle_multi_ -= 0.05f;
}

void BarrageBullet::lower()
{
	if (angle_multi_ < 0)
	{
		angle_multi_ = 0;
	}
	angle_multi_ += 0.05f;
}
