#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(sf::Vector2f spawn_position) : HealthEntity(spawn_position)
{
	tag = Tag::ENEMY;
	TEXTURE_PATH = "Assets/Sprites/Anek.png";
	TextureName = "Anek";
	//_DrawLayer = 5;
	_MovementSpeed = 80;
	_AccelerationSpeed = 0.1f;
	_AccelerationIncrease = 0.05f;
	CollisionIndex = 0;
	collision_box_offset_ = sf::Vector2f{ 0, 15.f };
	collision_box_.setSize(sf::Vector2f{ 41.0f,20.0f });
	texture_animation_offset = sf::IntRect(0, 0, 41, 52);
	animation_sheet_width_ = 41;
	bullet_spawn_offset_= { 35.f, 30.f };
	SetHealth(96);
}

void PlayerCharacter::MoveUp()
{
	if (this->EntitySprite.getPosition().y > 0)
	{
		
		Move((0.f), -250.f * pGameManager->GetDeltaTime());
	}
	
}

void PlayerCharacter::MoveDown()
{
	
	//std::cout << this->EntitySprite.getPosition().y;
	if (this->EntitySprite.getPosition().y < pGameManager->screen_height_ - this->EntitySprite.getTextureRect().height)
	{
		Move(0.f, 250.f * pGameManager->GetDeltaTime());
	}
	
}

void PlayerCharacter::Start()
{
	player_block_ = pGameManager->CreateEntity<PlayerBlock>(this->EntitySprite.getPosition() + sf::Vector2f{ 35, 0 });
	player_block_->SetActiveAndDrawn(false);
}

void PlayerCharacter::OnDeath()
{
	pGameManager->pPlayerGui->SetScreenActive(&PlayerGui::GameOverScreen);
}

void PlayerCharacter::Block()
{


}


void PlayerCharacter::Dash()
{
}

void PlayerCharacter::Jump()
{
}

void PlayerCharacter::ChargeAttack()
{
	if (shoot_cd_.getElapsedTime().asSeconds() > 0.08f)
	{
		pGameManager->CreateEntity<PlayerBullet>(this->EntitySprite.getPosition() + bullet_spawn_offset_, 300.f, 1.6f);
		shoot_cd_.restart();
	}
	
}

void PlayerCharacter::TakeDamage(int Damage)
{
	HealthEntity::TakeDamage(Damage);
	pGameManager->pPlayerGui->ChangeHpBar(-Damage);
}

void PlayerCharacter::AddStamina(const float value)
{
	if (value + stamina_ > MAX_STAMINA)
	{
		stamina_ = MAX_STAMINA;
	}
	else
	{
		stamina_ += value;
		pGameManager->pPlayerGui->ChangeStaminaBar(value);
	}

	
}

void PlayerCharacter::ReduceStamina(float value)
{
	if (stamina_ - value  < 0)
	{
		stamina_ = 0;
	}
	else
	{
		stamina_ -= value;
		pGameManager->pPlayerGui->ChangeStaminaBar(-value);
	}
}

void PlayerCharacter::Update()
{
	if (shooting_)
	{
		ChargeAttack();
	}
	
	if (blocking_ && stamina_ > 0 && !BlockCooldown)
	{
		ReduceStamina(STAMINA_INCREMENT * pGameManager->GetDeltaTime() * 60);
		std::cout << pGameManager->GetDeltaTime();
		player_block_->EnableHitBox();
		player_block_->SetActiveAndDrawn(true);
		player_block_->GetEntitySprite().setPosition(this->EntitySprite.getPosition() + sf::Vector2f{ 35, 0 });
	}
	if (stamina_ < STAMINA_INCREMENT && !BlockCooldown)
	{
		player_block_->DisableHitBox();
		player_block_->SetActiveAndDrawn(false);
		BlockCooldown = true;
		block_cd_clock_.restart();
	}
	
	if (block_cd_clock_.getElapsedTime().asSeconds() > 1.f && BlockCooldown)
	{
		BlockCooldown = false;
	}
	if (!blocking_)
	{
		player_block_->DisableHitBox();
		player_block_->SetActiveAndDrawn(false);
	}
	
	AddStamina(STAMINA_REGEN_INCREMENT);
}

sf::Vector2f PlayerCharacter::GetPositon()
{
		return this->EntitySprite.getPosition();
}

void PlayerCharacter::MoveLeft()
{
}

void PlayerCharacter::MoveRight()
{
}


