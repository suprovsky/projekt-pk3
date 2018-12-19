#ifndef CONFIGMANAGER_COKOLWIEK
#define CONFIGMANAGER_COKOLWIEK
#include "repository.h"
class ConfigManager :
	private repository
{
public:
	ConfigManager();
	virtual ~ConfigManager();
	std::wstring RepoLocation;
	std::wstring ConfigFileLocation;
	std::wstring GetRepoLocation();
	std::wstring SetRepoLocation(std::wstring LocationAddress);
};
#endif