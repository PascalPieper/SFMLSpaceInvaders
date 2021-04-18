#include "IOReading.h"

PP::IOReading::IOReading()
{
}

//Find the folder in which the .exe is placed. 
//FIXME: Only works for Windows when using an empty string to take the root folder
std::string PP::IOReading::ReadExecuteableFolder()
{
	return std::string();
}


void PP::IOReading::CreateDirectory(const std::string FolderName)
{
	if (!std::filesystem::exists(FolderName))
	{
		std::filesystem::create_directory(FolderName);
	}
}


bool PP::IOReading::CheckFileExists(FilePath * fp)
{
	if (std::filesystem::exists(fp->FullFilePath))
	{
		return true;
	}
	else
	{
		false;
	}

}

bool PP::IOReading::CheckKeyExists(std::string key, nlohmann::json j)
{
	
	return (j.contains(key)) ? true : false;
}
/*
int PP::IOReading::ProvideInt(FilePath *pfp, std::string key, int Fallback) 
{
	std::ifstream i(pfp->FullFilePath);
	nlohmann::json j;
	i >> j;
	if (CheckKeyExists(key, j) && i.peek != std::ifstream::traits_type::eof())
	{
		return j[key];
	}
	else
	{
		CreateDirectory(pfp->FolderName);
		j.clear();
		j << Fallback;
		Write(j, pfp->FullFilePath);
		return Fallback;
	}
}

int PP::IOReading::ProvideInt(FilePath *pfp, std::string key, int Fallback)
{
	std::ifstream i(pfp->FullFilePath);
	if (FileIsEmpty(i))
	{
		CreateDirectory(pfp->FolderName);
	}

	
		if (CheckFileExists(pfp))
		{

			nlohmann::json j;
			i >> j;
			if (j[key] != NULL)
			{
				return j[key];
			}
			else
			{
				throw std::invalid_argument("[IOReading] Cannot read: Passed key is not of type int");
			}
		}
		else
		{
			nlohmann::json j;
			Write(j, pfp->FullFilePath);
			return Fallback;
		}
}
*/

void PP::IOReading::Write(nlohmann::json j, std::string path)
{
	std::ofstream FileName;
	FileName.open(path);
	FileName << j;
	j.clear();
	FileName.close();
}

void PP::IOReading::SaveToFile(int *pInt, std::string key)
{
	nlohmann::json j;
	j[(key)] = *pInt;
	//PP::IOReading::Write(j);
}

bool PP::IOReading::FileIsEmpty(std::ifstream & pFile)
{
	{
		return pFile.peek() == std::ifstream::traits_type::eof();
	}
}

int PP::IOReading::ProvideInt(FilePath * fp, std::string key, int InitValue)
{
	CreateDirectory(fp->FolderName);

	if (CheckFileExists(fp))
	{
		std::ifstream i(fp->FullFilePath);
		nlohmann::json j;
		i >> j;
		if (j.contains(key))
		{
			return j[key];
		}
		else
		{
			j.clear();
			j[key] = InitValue;
			Write(j, fp->FullFilePath);
			return InitValue;
		}
	}
	else
	{
		nlohmann::json j;
		j[key] = InitValue;
		Write(j, fp->FullFilePath);
		return InitValue;
	}
}

float PP::IOReading::ProvideFloat(FilePath * fp, std::string key, float InitValue)
{
	CreateDirectory(fp->FolderName);

	if (CheckFileExists(fp))
	{
		std::ifstream i(fp->FullFilePath);
		nlohmann::json j;
		i >> j;
		if (j.contains(key))
		{
			return j[key];
		}
		else
		{
			j.clear();
			j[key] = InitValue;
			Write(j, fp->FullFilePath);
			return InitValue;
		}
	}
	else
	{
		nlohmann::json j;
		j[key] = InitValue;
		Write(j, fp->FullFilePath);
		return InitValue;
	}
}

std::string PP::IOReading::ProvideString(FilePath * fp, std::string key, std::string InitValue)
{
	CreateDirectory(fp->FolderName);

	if (CheckFileExists(fp))
	{
		std::ifstream i(fp->FullFilePath);
		nlohmann::json j;
		i >> j;
		if (j.contains(key))
		{
			return j[key];
		}
		else
		{
			j.clear();
			j[key] = InitValue;
			Write(j, fp->FullFilePath);
			return InitValue;
		}
	}
	else
	{
		nlohmann::json j;
		j[key] = InitValue;
		Write(j, fp->FullFilePath);
		return InitValue;
	}
}



