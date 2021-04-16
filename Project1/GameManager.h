#pragma once
#include <string>
#include <vector>
#include "IManager.h"
#include "SaveGameManager.h"
class GameManager 
{
public:
	GameManager();

public:
	mat_m::SaveGameManager saveGameManager;

};