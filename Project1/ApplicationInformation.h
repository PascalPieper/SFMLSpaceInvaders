#pragma once
#include <string>
#include <iostream>
 class ApplicationInformation
{
public:
	ApplicationInformation();
	~ApplicationInformation();
private:
	//Company and Game Details
	const std::string COMPANY_NAME = "M4Games";
	const std::string GAME_TITLE = "Morus Kara";
	const float APPLICATION_VERSION = 1.0f;

public:
	std::string GetCompanyName();
	std::string GetGameTitle();
	float GetApplicationVersion();
};