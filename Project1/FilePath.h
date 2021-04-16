#pragma once
#include <string>
struct FilePath
{
public:
	FilePath(std::string folderName, std::string fileName);
	std::string FolderName;
	std::string FileName;
public:
	std::string FullFilePath;
};