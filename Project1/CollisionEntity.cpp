#include "CollisionEntity.h"

CollisionEntity::CollisionEntity(sf::Vector2f SpawnPosition) : MoveEntity(SpawnPosition)
{
}

void CollisionEntity::RegisterEntity()
{
	pGameManager->RegisterToIndex(CollisionIndex, pGameManager->getEntity(this->GetID()));
}

void CollisionEntity::VerifyContinousCollisions()
{
	for (unsigned int i = 0; i < LastCollidedEntities.size(); i++)
	{
		if (!this->CollisionBox.getGlobalBounds().intersects(LastCollidedEntities.at(i)->CollisionBox.getGlobalBounds()))
		{
			LastCollidedEntities.erase(LastCollidedEntities.begin() + i);
		}
	}
	
}




bool CollisionEntity::DetectCollision(unsigned int CollisionLayer)
{
	auto &Clist = pGameManager->CollisionListings[CollisionLayer];
	VerifyContinousCollisions();

	for (unsigned int i = 0; i < Clist.size(); i++)
	{
		if (this->CollisionBox.getGlobalBounds().intersects(Clist.at(i)->CollisionBox.getGlobalBounds()))
		{
			if (std::find(Clist.begin(), Clist.end(), Clist.at(i)) == Clist.end())
			{
				LastCollidedEntities.push_back((pGameManager->CollisionListings[CollisionLayer].at(i)));
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;


}
