#include "CollisionEntity.h"

CollisionEntity::CollisionEntity(sf::Vector2f SpawnPosition) : MoveEntity(SpawnPosition)
{
}

void CollisionEntity::RegisterEntity()
{
	pGameManager->RegisterToIndex(CollisionIndex, this->GetID(), pGameManager->getEntity(this->GetID()));
	std::cout << "registered:" << pGameManager->getEntity(this->GetID());
}

void CollisionEntity::VerifyContinousCollisions()
{
	for (unsigned int i = 0; i < LastCollidedEntities.size(); i++)
	{
		if (!this->collision_box_.getGlobalBounds().intersects(LastCollidedEntities.at(i)->collision_box_.getGlobalBounds()))
		{
			LastCollidedEntities.erase(LastCollidedEntities.begin() + i);
		}
	}
	
}




bool CollisionEntity::CheckCollision(unsigned int CollisionLayer)
{
	auto &Clist = pGameManager->CollisionListings[CollisionLayer];
	
	auto size = Clist.size();
	for (auto it = Clist.begin(); it != Clist.end(); ++it)
	{
		if (Clist.size() != size)
		{
			break;
		}
		if (this->collision_box_.getGlobalBounds().intersects(it->second->collision_box_.getGlobalBounds()))
		{
			return true;
		}
		}

	return false;
}

void CollisionEntity::Destroy()
{
	pGameManager->UnRegisterFromIndex(CollisionIndex, this->GetID());
	pGameManager->RemoveEntity(this->GetID());
	
}

void CollisionEntity::Move(float x, float y)
{
	MoveEntity::Move(x, y);
	this->collision_box_.move(x, y);
}
