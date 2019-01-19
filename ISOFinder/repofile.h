#ifndef REPOFILE_COKOLWIEK
#define REPOFILE_COKOLWIEK
#include "repository.h"
#include <iostream>
#include <fstream>
class RepoFile :
	public Repository
{
public:
	RepoFile();
	RepoFile(std::wstring name, std::wstring filename, std::wstring filelock, std::wstring filedesc);
	RepoFile(std::wstring newFileLocation);
	virtual ~RepoFile();
	void SetSystemName(std::wstring newFileName);
	std::wstring GetSystemName();
	void SetUserDefinedName(std::wstring newFileFileName);
	std::wstring GetUserDefinedName();
	void SetFileDesc(std::wstring newFiledesc);
	std::wstring GetFileDesc();
	void SetFileLocation(std::wstring newFilelocation);
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

