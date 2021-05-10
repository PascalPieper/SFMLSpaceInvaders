#include "Enemy.h"

Enemy::Enemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Enemy01.png";
	TextureName = "Enemy01";
	//_DrawLayer = 5;
	_MovementSpeed = 80;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 0;
	//CollisionBox.setSize(sf::Vector2f{ 4.f,4.f });
	_MoveCoolDown = 5.f;
	_shootClock.restart();
}

void Enemy::MoveIntoScreen()
{
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
	ImGui::SliderFloat("offset X", &bullet_spawn_offset_.x, 0, 50);
	ImGui::SliderFloat("offset Y", &bullet_spawn_offset_.y, 0, 50);
	//if (_moveClock.getElapsedTime().asSeconds() > _MoveCoolDown)
	//{
	//	this->EntitySprite.move(0, -_MovementSpeed * pGameManager->GetDeltaTime());
	//}
	//else
	//{
	//	this->EntitySprite.move(0, _MovementSpeed * pGameManager->GetDeltaTime());
	//}
	//
	
	if (_shootClock.getElapsedTime().asSeconds() > _AttackCoolDown) {
		Shoot();
		_shootClock.restart();
	}
	


	ImGui::End();
}
