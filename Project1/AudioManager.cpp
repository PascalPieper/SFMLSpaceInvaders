#include "AudioManager.h"
AudioManager::AudioManager()
{

}

void AudioManager::PlayMusic(const std::string& filepath)
{
	//buffer_.loadFromFile(filepath);
	
	music_.openFromFile(filepath);
	music_.play();
}

void AudioManager::PlaySound(std::string filepath)
{
}
