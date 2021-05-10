#pragma once
#include "SFML/Audio.hpp"
#include <string>
class AudioManager 
{
public:
	AudioManager();
	
	void PlayMusic (const std::string& filepath);
	void PlaySound(std::string filepath);
	
	sf::SoundBuffer buffer_;
	sf::Music music_;

private:
	float MusicVolume = 10;
	float SFXVolume = 10;

public:
	float GetMusicVolume() const
	{
		return MusicVolume;
	}

	void SetMusicVolume(const float music_volume)
	{
		MusicVolume = music_volume;
	}

	float GetSfxVolume() const
	{
		return SFXVolume;
	}

	void SetSfxVolume(const float sfx_volume)
	{
		SFXVolume = sfx_volume;
	}


};