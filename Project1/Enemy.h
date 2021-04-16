#ifndef __ENEMY_H__
#define __ENEMY_H__

#pragma once
#include "IUpdate.h"
namespace PP
{
class Enemy : public IUpdate
{
public:
	Enemy(int health);
private:
	int _Health = 100;

public: 
	void Update();
	void test();
};
}
#endif // __ENEMY_H__