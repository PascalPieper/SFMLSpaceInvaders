#pragma once
#include "PlayerCharacter.h"
class PlayerManager
{
public:
	PlayerManager(std::shared_ptr<PlayerCharacter> player);


private:
	std::shared_ptr<PlayerCharacter> p_player_;

public:
	std::shared_ptr<PlayerCharacter> GetPPlayer() const
	{
		return p_player_;
	}

	void SetPPlayer(const std::shared_ptr<PlayerCharacter>& p_player)
	{
		p_player_ = p_player;
	}
};

inline PlayerManager::PlayerManager(std::shared_ptr<PlayerCharacter> player) : p_player_(player)
{
}
