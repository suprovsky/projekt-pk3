#ifndef REPOSITORY_COKOLWIEK
#define REPOSITORY_COKOLWIEK

#include "repository.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
class repository
{
public:
	repository();
	virtual ~repository();
	repository(std::string NewConfigFileLocation);
	int firstRun();
	void SetRepoLocation(std::string NewLocationAddress);
	std::string GetRepoLocation();
	void SetConfigLocation(std::string NewConfigLocation);
	int RepoSetupCall();
private:
	unsigned int ISOid;
	std::string RepoLocation;
	std::string ConfigFileLocation;
};
#endif // !REPOSITORY_COKOLWIEK
