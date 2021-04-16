#pragma once
#include <string>
#include <vector>
#include "IManager.h"
class GameManager 
{
public:
	GameManager();

private:
	std::vector<IManager> Managers;
};