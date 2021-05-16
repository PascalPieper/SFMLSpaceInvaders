#pragma once
#include "MoveEntity.h"
class ScrollingBackground : public MoveEntity
{
public:
	ScrollingBackground(sf::Vector2f spawn_position, std::string filepath, std::string texture_name, float speed);

protected:
	const float JUMPBACK_START = 0;
	int JUMPBACK_MAX = 418;
	const std::string filepath;

public:
	
	void ScrollRight();
	void Update();

};