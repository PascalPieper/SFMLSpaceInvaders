#pragma once
#include <string>
#include "GameManager.h"
class Scene
{
public:
	Scene(GameManager* pGameManager);
	~Scene();

protected:
	GameManager* _pGameManager;
	const std::string SCENE_NAME;
	bool _isLoaded = false;

	//Getters
public:
	const std::string GetSceneName() const { return SCENE_NAME; }

	//Functions
public:
	virtual bool LoadSceneContents();
	virtual bool UnloadSceneContents();
};