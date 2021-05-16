#include "SnakeEnemy.h"
SnakeEnemy::SnakeEnemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Mukade_animation.png";
	TextureName = "SnakeEnemy";
	_MovementSpeed = 21;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 2;
	collision_box_.setSize(sf::Vector2f{ 55.f,52.f });
	_MoveCoolDown = 5.f;
	_shootClock.restart();
	func = &SnakeEnemy::ShootAccelerated;
	texture_animation_offset = sf::IntRect(0, 0, 55, 52);
	animation_sheet_width_ = 495;
	_isOnScreen = false;
	SetHealth(600);
}

void SnakeEnemy::OnDeath()
{
	pGameManager->pLevelManager->ChangeBossCount(-1);
	pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->AddToPlayerScore(100);
	Destroy();
}

void SnakeEnemy::Start()
{
	se_.SetTargetSprite(&EntitySprite);
	se_.SetDelaySecondTime(0.023f);
}

void SnakeEnemy::MoveIntoScreen()
{
}

void SnakeEnemy::MoveUpDown()
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

void SnakeEnemy::ShootAccelerated()
{
	func = &SnakeEnemy::ShootBouncing;
	pGameManager->CreateEntity<BouncyBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60.f, 3.5f);

}

void SnakeEnemy::ShootBouncing()
{
	auto first = pGameManager->CreateEntity<BouncyBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 100.f, 1.6f);
	first->SetDirection(false);
	auto bullet = pGameManager->CreateEntity<BouncyBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 100.f, 1.6f);
	bullet->SetDirection(true);
	func = &SnakeEnemy::ShootAccelerated;
}
void SnakeEnemy::Shoot()
{
	(this->*func)();
}

void SnakeEnemy::MoveToScreenTop()
{

	if (this->EntitySprite.getPosition().y < pGameManager->screen_height_ / 5)
	{
		this->EntitySprite.move(0, _MovementSpeed * pGameManager->GetDeltaTime());
	}
	else
	{
		_isOnScreen = true;
	}
}

void SnakeEnemy::Update()
{
	se_.UpdateEffects();
	ProgressAnimation();
	
	ImGui::Begin("Snake Enemy");
	if (ImGui::Button("Destroy"))
	{
		Destroy();
	}
	ImGui::SliderFloat("Speed", &_MovementSpeed, 0, 300.f);
	ImGui::SliderFloat("Movement", &_MoveCoolDown, 0, 300.f);
	ImGui::Text("Time Elapsed = %f", _moveClock.getElapsedTime().asSeconds());
	ImGui::SliderFloat("offset X", &bullet_spawn_offset_.x, -50, 50);
	ImGui::SliderFloat("offset Y", &bullet_spawn_offset_.y, -50, 50);
	if (_isOnScreen)
	{
		if (CheckCollision(4))
		{
			se_.FlashSprite();
			pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->AddToPlayerScore(2);
			TakeDamage(5);
		}
		se_.UpdateEffects();
		MoveUpDown();

		if (_shootClock.getElapsedTime().asSeconds() > _AttackCoolDown) {
			Shoot();
			_shootClock.restart();
		}
	}
	else
	{
		MoveToScreenTop();
	}


	ImGui::End();
}