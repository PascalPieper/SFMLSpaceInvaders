#include "ScrollingBackground.h"
ScrollingBackground::ScrollingBackground(sf::Vector2f SpawnPosition) : MoveEntity(SpawnPosition)

{
	tag = Tag::BULLET;
	TEXTURE_PATH = "Assets/Background/ScrollingBackground01.png";
	TextureName = "Background01";
	//_DrawLayer = 0;
	_MovementSpeed = 120;
}
void ScrollingBackground::ScrollRight()
{
	if (EntitySprite.getPosition().x > -JUMPBACK_MAX)
	{
		//std::cout << EntitySprite.getPosition().x;
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
