#include "FilePath.h"

FilePath::FilePath(std::string folderName, std::string fileName)
{
	FolderName = folderName;
	FileName = fileName;
	FullFilePath = folderName + "\\" + fileName + ".json";
}
