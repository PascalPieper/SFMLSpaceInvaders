#pragma once
#include <string>
#include <memory>
#include <vector>
#include "IManager.h"
#include "SaveGameManager.h"
namespace mat_m 
{
	class EntityManager;
}

class GameManager 
{
public:
	GameManager();

public:
	std::shared_ptr<mat_m::EntityManager> EntityManager;
	//mat_m::EntityManager *EntityManager = nullptr;
	//mat_m::SaveGameManager saveGameManager;
};