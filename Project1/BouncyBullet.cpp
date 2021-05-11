#include "BouncyBullet.h"

BouncyBullet::BouncyBullet(sf::Vector2f SpawnPosition) : Bullet(SpawnPosition)
{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Sprites/Bullet.png";
	TextureName = "BouncyBullet";
	//_DrawLayer = 5;
	_MovementSpeed = 50;
	_AccelerationSpeed = 0.0f;
	_AccelerationIncrease = 0.00f;
	CollisionIndex = 0;
	//CollisionBox.setSize(sf::Vector2f{ 4.f,4.f });
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
		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), _MovementSpeed * pGameManager->GetDeltaTime());
	}
	if (_direction)
	{
		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), -_MovementSpeed * pGameManager->GetDeltaTime());
	}
		

	//_AccelerationSpeed += _AccelerationIncrease;
}

void BouncyBullet::Update()
{
	ImGui::Text("y positon = %f", EntitySprite.getPosition().y);
	ImGui::Text("x positon = %f", EntitySprite.getPosition().x);
	ImGui::Text("%s", _direction ? "true" : "false");
	FlyRight();
}
