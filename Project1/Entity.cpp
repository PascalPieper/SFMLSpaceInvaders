#include "Entity.h"
using namespace mat;


Entity::Entity(GameManager* gm)
{
	pgm = gm;
	thor::ResourceLoader<sf::Texture> Texture = thor::Resources::fromFile<sf::Texture>(TEXTURE_PATH);
	Texture.load();
	int a = pgm->saveGameManager.LoadInt("test");
}

Entity::~Entity()
{
	std::cout << "Entity has been destroyed.";
}

void Entity::SetTexture()
{
}

void Entity::Update()
{
}
