#pragma once
#include "MoveEntity.h"
class ScrollingBackground : public MoveEntity
{
public:
	ScrollingBackground(sf::Vector2f SpawnPosition);

protected:
	const float JUMPBACK_START = 0;
	const float JUMPBACK_MAX = 425;

public:
	void ScrollRight();
	void Update();

};