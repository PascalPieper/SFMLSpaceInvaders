#pragma once
#include "Scene.h"
#include <vector>
#include <SFML/Graphics.hpp>
class SceneManager
{
public:
	SceneManager(sf::RenderWindow window);

protected:
	std::vector<Scene> _scenes;

	//Getters
public:
	int GetSceneSize() { return (int)_scenes.size(); }

public:
	void LoadScene(unsigned int SceneNumber);
};