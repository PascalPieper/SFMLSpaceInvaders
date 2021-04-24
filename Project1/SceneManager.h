#pragma once
#include "Scene.h"
#include <vector>
class SceneManager
{
public:
	SceneManager();
	
	int getSceneSize() {return (int)Scenes.size();}
protected:
	std::vector<Scene> Scenes;
};