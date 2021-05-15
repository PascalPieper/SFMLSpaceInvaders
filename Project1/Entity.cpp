#include "Entity.h"
Entity::Entity(sf::Vector2f SpawnPosition)
{
	this->collision_box_.setPosition(this->EntitySprite.getPosition());
	//EntitySprite.setTexture(texture);
	//EntitySprite.setPosition(SpawnPosition);
}

Entity::~Entity()
{
}


void Entity::ProgressAnimation()
{
	if (sprite_animation_clock_.getElapsedTime().asMilliseconds() >= sprite_animation_speed_)
	{
		auto& result = texture_animation_offset;

		if (result.left >= animation_sheet_width_ - texture_animation_offset.width)
		{
			result.left = 0;
			EntitySprite.setTextureRect(result);
			sprite_animation_clock_.restart();
		}
		else
		{
			result.left += texture_animation_offset.width;
			EntitySprite.setTextureRect(result);
			sprite_animation_clock_.restart();
		}

	}
	
}

void Entity::Destroy()
{
	pGameManager->RemoveEntity(this->GetID());
}

void Entity::Update()
{
}
