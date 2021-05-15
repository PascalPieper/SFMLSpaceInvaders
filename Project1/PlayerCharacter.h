#pragma once
#include "IPlayerCharacter.h"
#include "HealthEntity.h"
#include "PlayerBlock.h"
#include "PlayerBullet.h"
#include <iostream>
class PlayerCharacter : public HealthEntity, IPlayerCharacter
{
public:
	PlayerCharacter(sf::Vector2f spawn_position);
	// Inherited via IPlayerCharacter
	std::shared_ptr<PlayerBlock> player_block_;
	virtual void MoveUp() override;
	virtual void MoveDown() override;
	virtual void Block() override;
	virtual void Dash() override;
	virtual void Jump() override;
	virtual void ChargeAttack() override;
	virtual void TakeDamage(int Damage) override;
	virtual void Start() override;
	void OnDeath() override;
	void Update() override;
	sf::Vector2f GetPositon() override;
	sf::Vector2f bullet_spawn_offset_;
	void MoveLeft() override;
	void MoveRight() override;



protected:
	bool shooting_ = false;


protected:
	sf::Clock block_cd_clock_;
	sf::Clock shoot_cd_;
	float stamina_ = 93.f;
	const float MAX_STAMINA = 93.f;
	const float STAMINA_INCREMENT = 3.6f;
	const float STAMINA_REGEN_INCREMENT = 0.3f;
	bool BlockCooldown = false;
public:
	float GetStamina() const
	{
		return stamina_;
	}

	void AddStamina(float value);
	void ReduceStamina(float value);
protected:
	bool blocking_ = false;
public:
	bool IsBlocking() const
	{
		return blocking_;
	}

	void SetBlocking(bool blocking)
	{
		blocking_ = blocking;
	}

public:
	bool IsShooting() const
	{
		return shooting_;
	}

	void SetShooting(bool shooting)
	{

		shooting_ = shooting;
	}
	void SetBulletSpawnOffset(const sf::Vector2f& bullet_spawn_offset)
	{
		bullet_spawn_offset_ = bullet_spawn_offset;
	}

	
};