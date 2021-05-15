#include "ScrollingBackground.h"

#include <utility>

ScrollingBackground::ScrollingBackground(const sf::Vector2f spawn_position, const std::string filepath, std::string texture_name, const float speed)
: MoveEntity(spawn_position), filepath(filepath)

{
	TEXTURE_PATH = filepath;
	tag = Tag::BACKGROUND;
	TextureName = texture_name;
	is_animated_ = false;
	//_DrawLayer = 0;
	_MovementSpeed = speed;
}
void ScrollingBackground::ScrollRight()
{
	if (EntitySprite.getPosition().x > -JUMPBACK_MAX)
	{
		EntitySprite.move(-_MovementSpeed * pGameManager->GetDeltaTime(), 0);
	}
	else
	{
		EntitySprite.setPosition(EntitySprite.getPosition().x + JUMPBACK_MAX, 0);
	}
	
}

void ScrollingBackground::Update()
{
	ScrollRight();
}
