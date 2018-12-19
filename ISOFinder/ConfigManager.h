#ifndef CONFIGMANAGER_COKOLWIEK
#define CONFIGMANAGER_COKOLWIEK
#include "repository.h"
class ConfigManager :
	private repository
{
public:
	ConfigManager();
	ConfigManager(std::wstring NewConfigFileLocation);
	virtual ~ConfigManager();
	std::wstring SetRepoLocation(std::wstring LocationAddress);
	std::wstring GetRepoLocation();
private:
	std::wstring RepoLocation;
	std::wstring ConfigFileLocation;


};
#endif