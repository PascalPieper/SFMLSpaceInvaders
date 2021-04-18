#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include "json.hpp"
#include <shlobj_core.h>
#include <stdexcept>
#include "ApplicationInformation.h"
#include <string>

using namespace nlohmann;
namespace mat_m
{
	class SaveGameManager
	{
	public:
		SaveGameManager(std::string SaveFileName);

	private:

		std::string SAVEGAME_PATH;
		std::string SAVEFILE_NAME = "TempSaveData.json";
		std::string FULL_FILE_PATH;

	private:
		bool SaveFolderExists();
		void CreateSaveFolder();



		void Write(json j);

		//Use this to return the Windows AppData path: Only works on Win7 and higher
		//NEEDS FIX: in order to save in browser or other systems we need to add functionality to detect the OS, too bad...
		std::string FindAppDataPath();

		//NOT IMPLEMENTED!
		//Only to be called once at a time during runtime.
		//IMPLEMENTATION: This needs to reference all Entities that should be saved at the end of a run
		//and overwrite the persistent keys with the temp keys
		void SaveGame();


	public:
		std::string GetAppDataPath();;

		//Write any int value to the Temporary Save File with key 
		void SaveToFile(int *i, std::string key);

		//Write any float value to the Temporary Save File with key 
		void SaveToFile(float *f, std::string key);

		//Write any string value to the Temporary Save File with key 
		void SaveToFile(std::string s, std::string key);

		//Returns any int from the Persistent SaveFile 
		int LoadInt(std::string key);

		float LoadFloat(std::string key);

		float LoadStringfromKey(std::string key);

		//Overwrite or insert the current Json contents to another File
		//Mainly utilized for the Temp and Persistent System
		//Clear Original decides if the json is to be emptied upon copying
		void OverwriteOtherFile(std::string FileName, bool clearOriginal);
	};
}