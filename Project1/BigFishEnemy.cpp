#include "BigFishEnemy.h"

#include "BarrageBullet.h"

BigFishEnemy::BigFishEnemy(sf::Vector2f SpawnPosition) : HealthEntity(SpawnPosition)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Fish_animation.png";
	TextureName = "BigFishEnemy";
	_MovementSpeed = 17;
	sprite_animation_speed_ = 170;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 2;
	collision_box_.setSize(sf::Vector2f{ 57.f,70.f });
	_MoveCoolDown = 5.f;
	_shootClock.restart();
	func = &BigFishEnemy::ShootAccelerated;
	texture_animation_offset = sf::IntRect(0, 0, 57, 70);
	animation_sheet_width_ = 228;
	_isOnScreen = false;
	SetHealth(450);

}

void BigFishEnemy::Start()
{
	se_.SetTargetSprite(&EntitySprite);
	se_.SetDelaySecondTime(0.032f);
}

void BigFishEnemy::MoveIntoScreen()
{
}


void BigFishEnemy::MoveToScreenTop()
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


void BigFishEnemy::MoveUpDown()
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

void BigFishEnemy::ShootAccelerated()
{
	func = &BigFishEnemy::ShootBouncing;
	pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.55f);
	pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.63f);
	pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.60f);

}

void BigFishEnemy::ShootBouncing()
{
	//pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.65f);
	//pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.63f);
	//pGameManager->CreateEntity<BarrageBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 60, 0, 0.60f);
	func = &BigFishEnemy::ShootAccelerated;
}
void BigFishEnemy::Shoot()
{
	(this->*func)();
}



void BigFishEnemy::Update()
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

void BigFishEnemy::OnDeath()
{
	pGameManager->GetEntityByType<PlayerCharacter>(pGameManager->current_player_id_)->AddToPlayerScore(120);
	Destroy();
}
