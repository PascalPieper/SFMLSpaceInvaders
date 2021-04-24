#include "Entity.h"
class MoveEntity : public Entity
{
public:
	MoveEntity(sf::Vector2f SpawnPosition);
protected:
	float _MovementSpeed;
	float _ActionSpeed;
	float _AccelerationSpeed;
	float _AccelerationIncrease;

	//getters
public:
	float GetMovementSpeed() { return _MovementSpeed; }
	float GetActionSpeed() { return _ActionSpeed; }
	float GetAccelerationSpeed() { return _AccelerationSpeed; }
	float AccelerationIncrease() { return _AccelerationIncrease; }

	//setters
public:
	void SetMovementspeed(float speed) { _MovementSpeed = speed; }
	void SetActionSpeed(float speed) { _ActionSpeed = speed; }
	void SetAccelerationSpeed(float speed) { _AccelerationSpeed = speed; }
	void SetAccelerationIncrease(float increase) { _AccelerationIncrease = increase; }

	//functions
protected:
	//NOT YET IMPLEMENTED
	void MoveToTarget(Entity target);

};
