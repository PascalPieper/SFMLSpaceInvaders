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
	if (sprite_animation_clock_.getElapsedTime().asMilliseconds() > sprite_animation_speed_)
	{
		auto& test = texture_animation_offset;

		if (test.left >= animation_sheet_width_ - texture_animation_offset.width)
		{
			test.left = 0;
			EntitySprite.setTextureRect(test);
		}
		else
		{
			test.left += texture_animation_offset.width;
			EntitySprite.setTextureRect(test);
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
