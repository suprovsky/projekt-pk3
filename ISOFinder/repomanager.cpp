#include "repomanager.h"



RepoManager::RepoManager()
{
}


RepoManager::~RepoManager()
{
	repoList.clear();
}

void RepoManager::AddToRepo(RepoFile& inputRepoFile)
{
	repoList.push_back(inputRepoFile);
}


void RepoManager::ShowAllFiles()
{
	if (repoList.empty())
	{
		std::wcout << L"The list is empty. There is nothing to watch." << std::endl;

	}
	else
	{
		std::wcout << L"This is an actual list of files in the repository:" << std::endl;
		for (auto x : repoList)
		{
			std::wcout << x << std::endl;
		}
	}

}

void RepoManager::FindInRepoBySystemName(std::wstring inputName)
{
	for (auto x : repoList)
	{
		if (x.GetSystemName() == inputName)
		{
			std::wcout << x << std::endl;
		}
	}
}

void RepoManager::FindInRepoByDesc(std::wstring inputDesc)
{
	for (auto x : repoList)
	{
		if (x.GetFileDesc() == inputDesc)
		{
			std::wcout << x << std::endl;
		}
	}
}

void RepoManager::FindInRepoByUserDefinedName(std::wstring inputUserDefinedName)
{
	for (auto x : repoList)
	{
		if (x.GetUserDefinedName() == inputUserDefinedName)
		{
			std::wcout << x << std::endl;
		}
	}
}

void RepoManager::FindInRepoByLocation(std::wstring inputLocation)
{
	for (auto x : repoList)
	{
		if (x.GetFileLocation() == inputLocation)
		{
			std::wcout << x << std::endl;
		}
	}
}

void RepoManager::RepoLoadFromFile()
{
}

bool RepoManager::RepoSaveToFile()
{
	return true;
}

void RepoManager::DeleteFromRepoBySystemName(std::wstring inputName)
{
	int deletedValue, iter = 0;
	std::list<RepoFile>::iterator listIter = repoList.begin();
	std::vector<int> availableValues;
	for (auto x : repoList){
		iter++;
		if (x.GetSystemName() == inputName)
		{
			std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
			availableValues.push_back(iter);
		}
	}
	if (availableValues.size() == 0){
		std::wcout << L"There are no matches for the following phrase: " << inputName << std::endl;
	}
	else{
		std::wcout << L"Please enter desired object index to be deleted: ";
		bool compare = false;
		do{
			std::wcin >> deletedValue;
			ValueChecker::IfInt();
			if (!(std::find(availableValues.begin(), availableValues.end(), deletedValue) != availableValues.end())){
				std::wcout << L"Value out of range. Please enter object index again: ";
			}
			else compare = true;
		} while (!(compare));
		std::advance(listIter, deletedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
		repoList.erase(listIter);
		std::wcout << L"Done, file deleted." << std::endl;
	}
}

void RepoManager::DeleteFromRepoByDesc(std::wstring inputDesc)
{
	int deletedValue, iter = 0;
	std::list<RepoFile>::iterator listIter = repoList.begin();
	std::vector<int> availableValues;
	for (auto x : repoList) {
		iter++;
		if (x.GetFileDesc() == inputDesc)
		{
			std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
			availableValues.push_back(iter);
		}
	}
	if (availableValues.size() == 0) {
		std::wcout << L"There are no matches for the following phrase: " << inputDesc << std::endl;
	}
	else {
		std::wcout << L"Please enter desired object index to be deleted: ";
		bool compare = false;
		do {
			std::wcin >> deletedValue;
			ValueChecker::IfInt();
			if (!(std::find(availableValues.begin(), availableValues.end(), deletedValue) != availableValues.end())) {
				std::wcout << L"Value out of range. Please enter object index again: ";
			}
			else compare = true;
		} while (!(compare));
		std::advance(listIter, deletedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
		repoList.erase(listIter);
		std::wcout << L"Done, file deleted." << std::endl;
	}
}

void RepoManager::DeleteFromRepoByUserDefinedName(std::wstring inputUserDefinedName)
{
	int deletedValue, iter = 0;
	std::list<RepoFile>::iterator listIter = repoList.begin();
	std::vector<int> availableValues;
	for (auto x : repoList) {
		iter++;
		if (x.GetUserDefinedName() == inputUserDefinedName)
		{
			std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
			availableValues.push_back(iter);
		}
	}
	if (availableValues.size() == 0) {
		std::wcout << L"There are no matches for the following phrase: " << inputUserDefinedName << std::endl;
	}
	else {
		std::wcout << L"Please enter desired object index to be deleted: ";
		bool compare = false;
		do {
			std::wcin >> deletedValue;
			ValueChecker::IfInt();
			if (!(std::find(availableValues.begin(), availableValues.end(), deletedValue) != availableValues.end())) {
				std::wcout << L"Value out of range. Please enter object index again: ";
			}
			else compare = true;
		} while (!(compare));
		std::advance(listIter, deletedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
		repoList.erase(listIter);
		std::wcout << L"Done, file deleted." << std::endl;
	}
}

void RepoManager::DeleteFromRepoByLocation(std::wstring inputLocation)
{
	int deletedValue, iter = 0;
	std::list<RepoFile>::iterator listIter = repoList.begin();
	std::vector<int> availableValues;
	for (auto x : repoList) {
		iter++;
		if (x.GetFileLocation() == inputLocation)
		{
			std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
			availableValues.push_back(iter);
		}
	}
	if (availableValues.size() == 0) {
		std::wcout << L"There are no matches for the following phrase: " << inputLocation << std::endl;
	}
	else {
		std::wcout << L"Please enter desired object index to be deleted: ";
		bool compare = false;
		do {
			std::wcin >> deletedValue;
			ValueChecker::IfInt();
			if (!(std::find(availableValues.begin(), availableValues.end(), deletedValue) != availableValues.end())) {
				std::wcout << L"Value out of range. Please enter object index again: ";
			}
			else compare = true;
		} while (!(compare));
		std::advance(listIter, deletedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
		repoList.erase(listIter);
		std::wcout << L"Done, file deleted." << std::endl;
	}
}

void RepoManager::DeleteFromRepoWholeList()
{
	int deletedValue, iter = 0;
	std::list<RepoFile>::iterator listIter = repoList.begin();
	std::vector<int> availableValues;
	for (auto x : repoList) {
		iter++;
		std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
		availableValues.push_back(iter);
	}
	std::wcout << L"Please enter desired object index to be deleted: ";
	bool compare = false;
	do {
		std::wcin >> deletedValue;
		ValueChecker::IfInt();
		if (!(std::find(availableValues.begin(), availableValues.end(), deletedValue) != availableValues.end())) {
			std::wcout << L"Value out of range. Please enter object index again: ";
		}
		else compare = true;
	} while (!(compare));
	std::advance(listIter, deletedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
	repoList.erase(listIter);
	std::wcout << L"Done, file deleted." << std::endl;
}
