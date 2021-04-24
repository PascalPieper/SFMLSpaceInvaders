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
			std::cout << _textures.size();
			return texture;
			//auto& texture = _textures[filePath];
			
			//this->_textures[name] = tex;
		}
		//return _textures.find(name)->second;
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


//void AssetManager::LoadFont(std::string name, std::string filePath)
//{
//}
