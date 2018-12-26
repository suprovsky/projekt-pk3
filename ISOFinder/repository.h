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
	int firstRun();
	void SetRepoLocation(std::wstring NewLocationAddress);
	std::wstring GetRepoLocation();
	int RepoSetupCall();
private:
	unsigned int ISOid;
	std::wstring RepoLocation;
};
#endif // !REPOSITORY_COKOLWIEK
