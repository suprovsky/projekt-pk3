#ifndef REPOFILE
#define REPOFILE
#include "repository.h"
#include <iostream>
#include <fstream>
class RepoFile :
	public Repository
{
public:
	RepoFile();
	RepoFile(std::wstring inputSystemName, std::wstring inputUserDefinedName, std::wstring inputFileLocation, std::wstring inputFileDesc);
	RepoFile(std::wstring newFileLocation);
	virtual ~RepoFile();
	void SetSystemName(std::wstring newSystemName);
	std::wstring GetSystemName();
	void SetUserDefinedName(std::wstring newUserDefinedName);
	std::wstring GetUserDefinedName();
	void SetFileDesc(std::wstring newFileDesc);
	std::wstring GetFileDesc();
	void SetFileLocation(std::wstring newFileLocation);
	std::wstring GetFileLocation();
	RepoFile& operator=(RepoFile &right);
	friend std::wostream& operator<<(std::wostream& output, RepoFile& right);
	friend std::wistream& operator>>(std::wistream& input, RepoFile& right);
private:
	std::wstring fileSystemName;
	std::wstring fileUserDefinedName;
	std::wstring fileDescription;
	std::wstring fileLocation;
};
#endif

