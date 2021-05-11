#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
class AssetManager 
{
public:
	AssetManager();
	~AssetManager();

private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;

public:
	sf::Texture& LoadTexture(std::string name, std::string fileName);
	bool UnLoadTexture(std::string name);

	sf::Font& LoadFont(std::string name, std::string filePath);
		bool UnloadFont(std::string name);
	//void LoadFont(std::string name, std::string fileName);
};