#include "Enemy.h"

Enemy::Enemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Bird_animation_sheet.png";
	TextureName = "Enemy01";
	_MovementSpeed = 35;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 2;
	collision_box_.setSize(sf::Vector2f{ 47.f,61.f });
	_MoveCoolDown = 5.f;
	_shootClock.restart();
	func = &Enemy::ShootAccelerated;
	texture_animation_offset = sf::IntRect( 0,0,47, 61 );
	animation_sheet_width_ = 564;
	SetHealth(1000);
	_isOnScreen = false;
}

void Enemy::OnDeath()
{
	Destroy();
}

void Enemy::Start()
{
	se_.SetTargetSprite(&EntitySprite);
	se_.SetDelaySecondTime(0.023f);
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

void Enemy::ShootAccelerated()
{
	pGameManager->CreateEntity<AcceleratedBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 5.f, 0.f);
	func = &Enemy::ShootBouncing;
}

void Enemy::ShootBouncing()
{
	pGameManager->CreateEntity<AcceleratedBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 7.f, 25.f);
	pGameManager->CreateEntity<AcceleratedBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 7.f, 85.f);
	pGameManager->CreateEntity<AcceleratedBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 5.f, -55.f);
	
	func = &Enemy::ShootAccelerated;
}
void Enemy::Shoot()
{
	(this->*func)();
}



void Enemy::Update()
{
	ProgressAnimation();
	ImGui::Begin("Enemy01");
	if (ImGui::Button("Destroy"))
	{
		Destroy();
	}

	if (_isOnScreen)
	{
		if (CheckCollision(4))
		{
			se_.FlashSprite();
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

void Enemy::MoveToScreenTop()
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
