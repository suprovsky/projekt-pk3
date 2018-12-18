#ifndef REPOSITORY_COKOLWIEK
#define REPOSITORY_COKOLWIEK


#include <iostream>

class repository
{
public:
	repository();
	virtual ~repository();
private:
	std::wstring RepoLocation;
	std::wstring ConfigFileLocation;
	unsigned int ISOid;
	std::wstring GetRepoLocation();
	std::wstring SetRepoLocation(std::wstring LocationAddress);
	
};
#endif // !REPOSITORY_COKOLWIEK
