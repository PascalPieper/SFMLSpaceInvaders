#include "SaveGameManager.h"

mat_m::SaveGameManager::SaveGameManager(std::string SaveFileName)
{
	SAVEFILE_NAME = SaveFileName;
	std::unique_ptr<ApplicationInformation> appInfo = std::make_unique<ApplicationInformation>();
		SAVEGAME_PATH = FindAppDataPath() + "\\" + appInfo->GetGameTitle();
		FULL_FILE_PATH = SAVEGAME_PATH + "\\" + SaveFileName + ".json";
		
	if (!SaveFolderExists()){ CreateSaveFolder(); }
	std::cout << SAVEGAME_PATH;
}

std::string mat_m::SaveGameManager::FindAppDataPath()
{
	std::filesystem::path path;
	PWSTR path_tmp;

	// Attempt to get user's AppData folder

	auto get_folder_path_ret = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path_tmp);

	// Error check
	if (get_folder_path_ret != S_OK)
	{
		CoTaskMemFree(path_tmp);
		throw std::invalid_argument("Could not get %APPDATA% path");
	}

	//Convert the Windows path type to a C++ path
	path = path_tmp;

	// Free memory
	CoTaskMemFree(path_tmp);

	

	return path.string();
}

std::string mat_m::SaveGameManager::GetAppDataPath()
{
	return SAVEGAME_PATH;
}

bool mat_m::SaveGameManager::SaveFolderExists()
{
	if (std::filesystem::exists(SAVEGAME_PATH))
	{
		return true;
	}
	return false;
}

void mat_m::SaveGameManager::CreateSaveFolder()
{
	std::filesystem::create_directory(SAVEGAME_PATH);
}

void mat_m::SaveGameManager::OverwriteOtherFile(std::string FileName, bool clearOriginal)
{
	std::ifstream i(FULL_FILE_PATH);
	std::ofstream SaveGame;
	json j;
	i >> j;
	SaveGame.open(SAVEGAME_PATH + "\\" + FileName + ".json");
	SaveGame << j;
	if (clearOriginal)
	{
		j.clear();
	}
	SaveGame.close();
}

void mat_m::SaveGameManager::Write(json j)
{
	std::ofstream SaveGame;
	SaveGame.open(FULL_FILE_PATH);
	SaveGame << j;
	j.clear();
	SaveGame.close();
}

void mat_m::SaveGameManager::SaveToFile(int *i, std::string key)
{
	json j;
	j[(key)] = *i;
	SaveGameManager::Write(j);

}

void mat_m::SaveGameManager::SaveToFile(float *f, std::string key)
{
	json j;
	j[(key)] = *f;
	SaveGameManager::Write(j);
}

void mat_m::SaveGameManager::SaveToFile(std::string s, std::string key)
{
	json j;
	j[(key)] = s;
	SaveGameManager::Write(j);
}

int mat_m::SaveGameManager::LoadInt(std::string key)
{
	std::ifstream i(SAVEGAME_PATH);
	json j;
	i >> j;
	if (j[key].is_number_integer())
	{
		return j[key];
	}
	else
	{
		throw std::invalid_argument("[SAVEGAMEMANAGER] Cannot read: Passed key is not of type int");
	}
}

float mat_m::SaveGameManager::LoadFloat(std::string key)
{
	std::ifstream i(SAVEGAME_PATH);
	json j;
	i >> j;
	if (j[key].is_number_float())
	{
		return j[key];
	}
	else
	{
		throw std::invalid_argument("[SAVEGAMEMANAGER] Cannot read: Passed key is not of type float");
	}
}

float mat_m::SaveGameManager::LoadStringfromKey(std::string key)
{
	return 0.0f;
}
