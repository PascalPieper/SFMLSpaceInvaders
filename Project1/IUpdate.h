#pragma once
class IUpdate 
{
public:
	virtual ~IUpdate() = default;
	virtual void Update() = 0;
};