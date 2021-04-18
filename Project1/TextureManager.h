#pragma once
#include <Thor/Resources.hpp>
#include <SFML/Graphics.hpp>
#include <map>
class TextureManager 
{
public:
	TextureManager();

public:
	thor::ResourceLoader<sf::Texture> Loader;
	thor::ResourceHolder<sf::Texture, std::string> Textureholder;

public:
	void RegisterTexture(std::string FilePath);
};