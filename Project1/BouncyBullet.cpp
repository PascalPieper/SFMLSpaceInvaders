#include "BouncyBullet.h"

#include "PlayerCharacter.h"

BouncyBullet::BouncyBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi) : Bullet(SpawnPosition)
{
	tag = Tag::BULLET;
	is_animated_ = false;
	TEXTURE_PATH = "Assets/Sprites/BouncyBullet2.png";
	TextureName = "BouncyBullet";
	//_DrawLayer = 5;
	_MovementSpeed = move_speed;
	_AccelerationSpeed = 0.0f;
	_AccelerationIncrease = 0.00f;
	CollisionIndex = 3;
	collision_box_.setSize(sf::Vector2f{ 6.f,6.f });
	angle_multi_ = angle_multi;
}


void BouncyBullet::FlyRight()
{
	if (EntitySprite.getPosition().y < 0 + EntitySprite.getTexture()->getSize().y / 4)
	{
		_direction = false;
	}
	
	if (EntitySprite.getPosition().y > 200 )
	{
		_direction = true;
	}
	if (!_direction)
	{
		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), _MovementSpeed * pGameManager->GetDeltaTime() * angle_multi_);
	}
	if (_direction)
	{
		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), -_MovementSpeed * pGameManager->GetDeltaTime() * angle_multi_);
	}
		

	//_AccelerationSpeed += _AccelerationIncrease;
}

void BouncyBullet::Update()
{
	
	ImGui::Text("y positon = %f", EntitySprite.getPosition().y);
	ImGui::Text("x positon = %f", EntitySprite.getPosition().x);
	ImGui::Text("%s", _direction ? "true" : "false");
	FlyRight();
	OutOfBoundsCheck();
	if (CheckCollision(0))
	{
		pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->TakeDamage(5);
		Destroy();
	}
	if (CheckCollision(1))
	{
		Destroy();
	}

	}
