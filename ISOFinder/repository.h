#ifndef REPOSITORY_COKOLWIEK
#define REPOSITORY_COKOLWIEK

#include <fstream>
#include <iostream>

class repository
{
public:
	repository();
	virtual ~repository();
	repository(std::wstring NewConfigFileLocation);
	void firstRun();
	void SetRepoLocation(std::wstring NewLocationAddress);
	std::wstring GetRepoLocation();
	void SetConfigLocation(std::wstring NewConfigLocation);
private:
	unsigned int ISOid;
	std::wstring RepoLocation;
	std::wstring ConfigFileLocation;
};
#endif // !REPOSITORY_COKOLWIEK
