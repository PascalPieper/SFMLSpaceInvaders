#ifndef __IOREADING_H__
#define __IOREADING_H__

#pragma once
#include <fstream>
#include <filesystem>
#include "json.hpp"
#include <stdexcept>
#include <string>
#include "FilePath.h"

namespace PP{

class IOReading 
{
public:
	IOReading();

protected:
	nlohmann::json _j;

protected:
	//Find the folder in which the .exe is placed. 
	//FIXME: Only works for Windows when using an empty string to take the root folder
	std::string ReadExecuteableFolder();

	//Checks if a directory already exists and if not creates it
	virtual void CreateDirectory(std::string FolderName);

	//Check if the file at the given path already exists and return true if is does
	virtual bool CheckFileExists(FilePath *pfp);

	virtual bool CheckKeyExists(std::string key, nlohmann::json j);

	//virtual void CreateFile(std::string FileName);
	void Write(nlohmann::json j, std::string path);

	void SaveToFile(int *pInt, std::string key);

	bool FileIsEmpty(std::ifstream& pFile);

public:
	//loads an int from a file or creates an entry in a new file and returns the InitValue as the starting value.
	//This has to be called at least once to produce the file and the key inside the .json and can henceforth be used as the default read
	int ProvideInt(FilePath *fp, std::string key, int InitValue);
};
}

#endif // __IOREADING_H__