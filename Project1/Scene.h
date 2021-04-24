#pragma once
#include <string>
#include "GameManager.h"
class Scene
{
public:
	Scene(GameManager* pGameManager);
	~Scene();
	
	virtual bool LoadScene();
	const std::string GetSceneName() const {return SCENE_NAME;}

protected:
	const std::string SCENE_NAME;
	bool IsLoaded = false;

};