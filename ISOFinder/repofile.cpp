#include "repofile.h"



RepoFile::RepoFile()
{
	fileLocation = L"./";
}

RepoFile::RepoFile(std::wstring name, std::wstring filename, std::wstring filelock, std::wstring filedesc)
{
	fileSystemName = name;
	fileUserDefinedName = filename;
	fileLocation = filelock;
	fileDescription = filedesc;
}

RepoFile::RepoFile(const std::wstring NewISOlocation = L"./") : fileLocation(NewISOlocation)
{
}


RepoFile::~RepoFile()
{
}

void RepoFile::SetSystemName(std::wstring NewISOname)
{
	fileSystemName = NewISOname;
}

std::wstring RepoFile::GetSystemName()
{
	return fileSystemName;
}

void RepoFile::SetUserDefinedName(std::wstring NewISOfilename)
{
	fileUserDefinedName = NewISOfilename;
}

std::wstring RepoFile::GetUserDefinedName()
{
	return fileUserDefinedName;
}

void RepoFile::SetFileDesc(std::wstring NewISOdesc)
{
	fileDescription = NewISOdesc;
}

std::wstring RepoFile::GetFileDesc()
{
	return fileDescription;
}

void RepoFile::SetFileLocation(std::wstring NewISOlocation)
{
	fileLocation = NewISOlocation;
}

std::wstring RepoFile::GetFileLocation()
{
	return fileLocation;
}

RepoFile & RepoFile::operator=(RepoFile & right)
{
	this->fileDescription = right.fileDescription;
	this->fileUserDefinedName = right.fileUserDefinedName;
	this->fileLocation = right.fileLocation;
	this->fileSystemName = right.fileSystemName;
	return *this;
}

std::wostream & operator<<(std::wostream & output, RepoFile & right)
{
	output << L"System file name: " << right.fileSystemName << std::endl << L"Description: " << right.fileDescription << std::endl;
	output << L"User defined file name: " << right.fileUserDefinedName << std::endl << L"Location: " << right.fileLocation << std::endl;
	return output;
}
