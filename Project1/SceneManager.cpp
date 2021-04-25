#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow window)
{
}

void SceneManager::LoadScene(unsigned int SceneNumber)
{
	if (_scenes[SceneNumber].LoadSceneContents())
	{
		return;
	}
	else
	{
		throw std::invalid_argument("[SceneManager] Scene was unable to Load");
	}
	
	
}
