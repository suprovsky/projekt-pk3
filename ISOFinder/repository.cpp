#include "repository.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "menu.h"

Repository::Repository()
{
	RepoLocation = L"-";
}


Repository::~Repository()
{
}

int Repository::firstRun()
{
	std::wstring path;
	std::wofstream file;
	path = _wgetenv(L"appdata");
	path += L"\\FileFinder.cfg";
	file.open(path.c_str(), std::ios::out | std::ios::trunc);
	if (file.is_open())
	{
		std::wcout << L"This is the first run of FileFinder. ";
		std::wcout << L"The configuration file will be created in:" << std::endl;
		std::wcout << path << std::endl << std::endl;
		std::wcout << L"Click ENTER to continue.";
		file << RepoLocation;
		file.close();
		std::cin.get();
		return 0;
	}
	else
	{
		std::wcerr << L"ERROR: file FileFinder.cfg could not be created in: " << std::endl;
		std::wcerr << path << std::endl;
		std::wcerr << L"Please check if you are authorised to create a file in this directory.";
		std::wcout << std::endl << std::endl << L"Click ENTER to continue.";
		std::cin.get();
		exit(1);
		return 1;
	}
}
void Repository::SetRepoLocation(std::wstring NewLocationAddress)
{
	RepoLocation = NewLocationAddress;
}

std::wstring Repository::GetRepoLocation()
{
	return RepoLocation;
}

void Repository::RepoStartup()
{
	std::wstring path;
	std::wifstream file;
	path = _wgetenv(L"appdata");
	path += L"\\FileFinder.cfg";
	file.open(path.c_str(), std::ios::in);
	if (file.is_open())
	{
		file >> RepoLocation;
		file.close();
	}
	else
	{
		firstRun();
	}
}
