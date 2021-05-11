#include "Enemy.h"

Enemy::Enemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Enemy01.png";
	TextureName = "Enemy01";
	//_DrawLayer = 5;
	_MovementSpeed = 35;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 0;
	collision_box_.setSize(sf::Vector2f{ 4.f,4.f });
	_MoveCoolDown = 5.f;
	_shootClock.restart();
}

void Enemy::MoveIntoScreen()
{
}

void Enemy::MoveUpDown()
{
	if (this->EntitySprite.getPosition().y >= pGameManager->screen_height_ - this->EntitySprite.getTextureRect().height)
	{
		_movedirection = !_movedirection;
	}
	if (this->EntitySprite.getPosition().y <= 0)
	{
		_movedirection = !_movedirection;
	}

	if (_movedirection)
	{
		this->EntitySprite.move(0, -_MovementSpeed * pGameManager->GetDeltaTime());
	}
	else
	{
		this->EntitySprite.move(0, _MovementSpeed * pGameManager->GetDeltaTime());
	}
}

void Enemy::Shoot()
{
	pGameManager->CreateEntity<AcceleratedBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_);
	//ImGui::Begin("Toggle Background");
}

void Enemy::Update()
{
	ImGui::Begin("Enemy01");
	ImGui::SliderFloat("Speed", &_MovementSpeed, 0, 300.f);
	ImGui::SliderFloat("Movement", &_MoveCoolDown, 0, 300.f);
	ImGui::Text("Time Elapsed = %f", _moveClock.getElapsedTime().asSeconds());
	ImGui::SliderFloat("offset X", &bullet_spawn_offset_.x, -50, 50);
	ImGui::SliderFloat("offset Y", &bullet_spawn_offset_.y, -50, 50);
	MoveUpDown();
	/*
	if (_moveClock.getElapsedTime().asSeconds() > _MoveCoolDown)
	{
		
	}
	else
	{
		this->EntitySprite.move(0, _MovementSpeed * pGameManager->GetDeltaTime());
	}
	*/
	
	if (_shootClock.getElapsedTime().asSeconds() > _AttackCoolDown) {
		Shoot();
		_shootClock.restart();
	}
	


	ImGui::End();
}
