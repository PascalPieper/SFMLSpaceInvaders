#pragma once
#include "Enemy.h"

class FireEnemy : public Enemy
{
public:
	FireEnemy();
	void test();
protected:
	std::string TEXTURE_PATH = "Assets/Sprites/Enemy.png";
};