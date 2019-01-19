#ifndef REPOSITORY_COKOLWIEK
#define REPOSITORY_COKOLWIEK

#include "repository.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
class Repository
{
public:
	Repository();
	virtual ~Repository();
	int firstRun();
	void SetRepoLocation(std::wstring NewLocationAddress);
	std::wstring GetRepoLocation();
	void RepoStartup();
private:
	unsigned int ISOid;
	std::wstring RepoLocation;
};
#endif // !REPOSITORY_COKOLWIEK
