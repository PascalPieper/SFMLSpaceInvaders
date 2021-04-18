#pragma once
#include "EntityManager.h"
#include <Thor/Input.hpp>
#include <SFML/Graphics.hpp>
class InputManager 
{
public:
	
	InputManager(EntityManager* Em);
	thor::Action a();
};