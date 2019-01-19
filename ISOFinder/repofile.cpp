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
	output << L"System file name: " << right.fileSystemName << std::endl;
	output << L"Description: " << right.fileDescription << std::endl;
	output << L"User defined file name: " << right.fileUserDefinedName << std::endl;
	output << L"Location: " << right.fileLocation << std::endl;
	return output;
}

std::wistream & operator>>(std::wistream & input, RepoFile & right)
{//syntax: fileSystemName,fileUserDefinedName,fileDescription,fileLocation
	std::wstring inputSystemName, inputUserDefinedName, inputDescription, inputLocation;
	input.ignore(18);//L"System file name: "
	input >> inputSystemName;
	right.SetSystemName(inputSystemName);
	input.ignore(13+1);//L"Description: " + std::endl
	input >> inputUserDefinedName;
	right.SetSystemName(inputDescription);
	input.ignore(24+1);//L"User defined file name: " + std::endl
	input >> inputUserDefinedName;
	right.SetSystemName(inputUserDefinedName);
	input.ignore(11+1);//L"Location: " + std::endl
	input >> inputUserDefinedName;
	right.SetSystemName(inputLocation);
	input.ignore(1);//std::endl
	return input;
}
