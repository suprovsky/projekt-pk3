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
	void SetISOname(std::wstring newFileName);
	std::wstring GetISOname();
	void SetISOfilename(std::wstring newFileFileName);
	std::wstring GetISOfilename();
	void SetISOdesc(std::wstring newFiledesc);
	std::wstring GetISOdesc();
	void SetISOlocation(std::wstring newFilelocation);
	std::wstring GetISOlocation();
	RepoFile& operator=(RepoFile &right);
private:
	std::wstring fileName;
	std::wstring fileFilename;
	std::wstring fileDescription;
	std::wstring fileLocation;
	//auto ISOmodificationTime;

};
#endif

