#include "repofile.h"



RepoFile::RepoFile()
{
	fileLocation = L"./";
}

RepoFile::RepoFile(std::wstring name, std::wstring filename, std::wstring filelock, std::wstring filedesc)
{
	fileName = name;
	fileFilename = filename;
	fileLocation = filelock;
	fileDescription = filedesc;
}

RepoFile::RepoFile(const std::wstring NewISOlocation = L"./") : fileLocation(NewISOlocation)
{
}


RepoFile::~RepoFile()
{
}

void RepoFile::SetISOname(std::wstring NewISOname)
{
	fileName = NewISOname;
}

std::wstring RepoFile::GetISOname()
{
	return fileName;
}

void RepoFile::SetISOfilename(std::wstring NewISOfilename)
{
	fileFilename = NewISOfilename;
}

std::wstring RepoFile::GetISOfilename()
{
	return fileFilename;
}

void RepoFile::SetISOdesc(std::wstring NewISOdesc)
{
	fileDescription = NewISOdesc;
}

std::wstring RepoFile::GetISOdesc()
{
	return fileDescription;
}

void RepoFile::SetISOlocation(std::wstring NewISOlocation)
{
	fileLocation = NewISOlocation;
}

std::wstring RepoFile::GetISOlocation()
{
	return fileLocation;
}

RepoFile & RepoFile::operator=(RepoFile & right)
{
	this->fileDescription = right.fileDescription;
	this->fileFilename = right.fileFilename;
	this->fileLocation = right.fileLocation;
	this->fileName = right.fileName;
	return *this;
}
