#pragma once
#include <string>
#include <vector>
#include "IManager.h"
#include "SaveGameManager.h"
#include "EntityManager.h"
class GameManager 
{
public:
	GameManager();

public:
	mat_m::SaveGameManager saveGameManager;
	mat_m::EntityManager EntityManager;
};