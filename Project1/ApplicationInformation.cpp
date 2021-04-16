#include "ApplicationInformation.h"


ApplicationInformation::ApplicationInformation()
{
}

ApplicationInformation::~ApplicationInformation()
{
}

std::string ApplicationInformation::GetCompanyName()
{
	return COMPANY_NAME;
}

std::string ApplicationInformation::GetGameTitle()
{
	return GAME_TITLE;
}

float ApplicationInformation::GetApplicationVersion()
{
	return APPLICATION_VERSION;
}
