#include "AssetManager.h"
AssetManager::AssetManager()
{

}
AssetManager::~AssetManager()
{
}
sf::Texture& AssetManager::LoadTexture(std::string name, std::string filePath)
{

	auto KeyValuePair = _textures.find(name);
	if (KeyValuePair != _textures.end())
	{
		return (KeyValuePair->second);
	}
	else
	{
		auto& texture = _textures[name];

		if (texture.loadFromFile(filePath))
		{
			return texture;
		}
	}

}

bool AssetManager::UnLoadTexture(std::string name)
{
	if (_textures.erase(name))
	{
		return true;
	}
	return false;
}