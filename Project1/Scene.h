#pragma once
#include <string>
#include "GameManager.h"
#include "PlayerCharacter.h"
#include <functional>
class Scene
{
public:
	Scene(GameManager* pGameManager);
	~Scene();

protected:
	GameManager* _pGameManager;
	const std::string SCENE_NAME = "default Scene";
	bool _isLoaded = false;

	//Getters
public:
	const std::string GetSceneName() const { return SCENE_NAME; }

	//Functions
public:
	virtual void StartScene(PlayerCharacter& playerCharacter);
	virtual bool LoadSceneContents();
	virtual bool UnloadSceneContents();
};