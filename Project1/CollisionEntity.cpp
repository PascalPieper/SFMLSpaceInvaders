#include "CollisionEntity.h"

CollisionEntity::CollisionEntity(sf::Vector2f SpawnPosition) : MoveEntity(SpawnPosition)
{
}

void CollisionEntity::RegisterEntity()
{
	pGameManager->RegisterToIndex(CollisionIndex, pGameManager->getEntity(this->GetID()));
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
	//VerifyContinousCollisions();

	for (unsigned int i = 0; i < Clist.size(); i++)
	{
		//std::cout << collision_box_.getGlobalBounds().height;
		if (this->collision_box_.getGlobalBounds().intersects(Clist.at(i)->collision_box_.getGlobalBounds()))
		{
			return true;
		}
	/*		if (std::find(Clist.begin(), Clist.end(), Clist.at(i)) == Clist.end())
			{
				LastCollidedEntities.push_back((pGameManager->CollisionListings[CollisionLayer].at(i)));
				
			}*/
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
