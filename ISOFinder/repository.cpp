#include "repository.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


repository::repository()
{
}


repository::~repository()
{
}

repository::repository(std::string NewConfigFileLocation)
{
}

int repository::firstRun()
{
	std::string path;
	std::ofstream file;
	path = getenv("appdata");
	path += "\\ISOfinder.dat";
	std::filesystem::exists(path);
	if (!(std::filesystem::exists(path)))
	{
		file.open(path.c_str(), std::ios::out | std::ios::app);
		if (file.is_open())
		{
			std::cout << "This is the first run of ISOFinder. ";
			std::cout << "The configuration file will be created in:" << std::endl;
			std::cout << path << std::endl << std::endl;
			std::cout << "Click ENTER to continue.";
			std::cin.get();
			system("cls");
			return 0;
		}
		else
		{
			std::cerr << "ERROR: file ISOfinder.dat could not be created in: " << std::endl;
			std::cerr << path << std::endl;
			std::cerr << "Please check if you are authorised to create a file in this directory.";
			std::cout << std::endl << std::endl << "Click ENTER to continue.";
			std::cin.get();
			system("cls");
			return 1;
		}
	}
}

void repository::SetRepoLocation(std::string NewLocationAddress)
{
}

std::string repository::GetRepoLocation()
{
	return std::string();
}

void repository::SetConfigLocation(std::string NewConfigLocation)
{
}

int repository::RepoSetupCall()
{
	return 0;
}
