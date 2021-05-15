#include "PlayerBullet.h"
#include "PlayerCharacter.h"

PlayerBullet::PlayerBullet(sf::Vector2f SpawnPosition, float move_speed, float angle_multi) : Bullet(SpawnPosition)
{
	tag = Tag::BULLET;
	is_animated_ = false;
	TEXTURE_PATH = "Assets/Sprites/PlayerBaseBullet.png";
	TextureName = "PlayerBaseBullet";
	//_DrawLayer = 5;
	_MovementSpeed = move_speed;
	_AccelerationSpeed = 0.0f;
	_AccelerationIncrease = 0.00f;
	CollisionIndex = 4;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
	angle_multi_ = angle_multi;
}


void PlayerBullet::FlyRight()
{

		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), _MovementSpeed * pGameManager->GetDeltaTime() * angle_multi_);

		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), -_MovementSpeed * pGameManager->GetDeltaTime() * angle_multi_);


	//_AccelerationSpeed += _AccelerationIncrease;
}

void PlayerBullet::FlyLeft()
{
	EntitySprite.move(_MovementSpeed * pGameManager->GetDeltaTime(), 0);
}

void PlayerBullet::Update()
{

	ImGui::Text("y positon = %f", EntitySprite.getPosition().y);
	ImGui::Text("x positon = %f", EntitySprite.getPosition().x);
	ImGui::Text("%s", _direction ? "true" : "false");
	FlyLeft();
	OutOfBoundsCheck();
	//if (CheckCollision(1))
	//{
	//	Destroy();
	//	return;
	//}
	if (CheckCollision(2))
	{
		//pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->TakeDamage(6);
		Destroy();
	};
}
