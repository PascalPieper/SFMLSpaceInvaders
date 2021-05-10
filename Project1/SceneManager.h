#pragma once
#include "Scene.h"
#include <map>
#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
class SceneManager : public IUpdate
{
public:
	SceneManager(sf::RenderWindow window);

protected:
	std::map<unsigned int, Scene> _scenes;

	Scene *pCurrentScene;
	//PlayerCharacter _currentPlayerCharacter;

	//Getters
public:
	//void NewRun();
	int GetSceneSize() { return (int)_scenes.size(); }
	//PlayerCharacter &GetPlayerCharacter() { return _currentPlayerCharacter; }

public:
	void LoadScene(unsigned int SceneNumber);

	virtual void Update() override;
};