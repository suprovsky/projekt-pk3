#include "repomanager.h"



RepoManager::RepoManager()
{
	changesNotSaved = false;
	listPath = _wgetenv(L"appdata");
	listPath += L"\\FileFinder.dat";
	RepoLoadFromFile();
}


RepoManager::~RepoManager()
{
	repoList.clear();
}

void RepoManager::AddToRepo(RepoFile& inputRepoFile)
{
	repoList.push_back(inputRepoFile);
	changesNotSaved = true;
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
	RepoFile inputObject;
	std::wstring inputString;
	std::wifstream file;
	file.open(listPath, std::ios::in);
	if (file.is_open())
	{
		while (!(file.eof()))
		{
			std::getline(file, inputString, L',');
			inputObject.SetSystemName(inputString);
			std::getline(file, inputString, L',');
			inputObject.SetFileDesc(inputString);
			std::getline(file, inputString, L',');
			inputObject.SetUserDefinedName(inputString);
			std::getline(file, inputString, L',');
			inputObject.SetFileLocation(inputString);
			std::getline(file, inputString, L'\n');
			repoList.push_back(inputObject);
		}
		file.close();
	}
}

bool RepoManager::RepoSaveToFile()
{
	std::wofstream file;
	file.open(listPath, std::ios::out | std::ios::trunc);
	if (file.is_open())
	{
		for (auto x : repoList)
		{
			file << x.GetSystemName() << "," << x.GetFileDesc() << "," << x.GetUserDefinedName() << "," << x.GetFileLocation() << "," << std::endl;
		}
		file.close();
		ValueChecker::DeleteLastCharacter(listPath);
		changesNotSaved = false;
		return true;
	}
	else
	{
		return false;
	}
}

void RepoManager::DeleteFromRepoBySystemName(std::wstring inputName)
{
	if (!(repoList.empty()))
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
			changesNotSaved = true;
		}
	}
	else std::wcout << L"Actual repository is empty. There is nothing do delete." << std::endl;
}

void RepoManager::DeleteFromRepoByDesc(std::wstring inputDesc)
{
	if (!(repoList.empty()))
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
			changesNotSaved = true;
		}
	}
	else std::wcout << L"Actual repository is empty. There is nothing do delete." << std::endl;
}

void RepoManager::DeleteFromRepoByUserDefinedName(std::wstring inputUserDefinedName)
{
	if (!(repoList.empty()))
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
			changesNotSaved = true;
		}
	}
	else std::wcout << L"Actual repository is empty. There is nothing do delete." << std::endl;
}

void RepoManager::DeleteFromRepoByLocation(std::wstring inputLocation)
{
	if (!(repoList.empty()))
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
			changesNotSaved = true;
		}
	}
	else std::wcout << L"Actual repository is empty. There is nothing do delete." << std::endl;
}

void RepoManager::DeleteFromRepoWholeList()
{
	if (!(repoList.empty())){
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
		changesNotSaved = true;
	}
	else std::wcout << L"Actual repository is empty. There is nothing do delete." << std::endl;
}

void RepoManager::EditFileFromWholeList()
{
	if (!(repoList.empty())){
		int selectedValue, iter = 0;
		std::list<RepoFile>::iterator listIter = repoList.begin();
		std::vector<int> availableValues;
		for (auto x : repoList) {
			iter++;
			std::wcout << L"Object index: " << iter << std::endl << x << std::endl << std::endl;
			availableValues.push_back(iter);
		}
		std::wcout << L"Please enter desired object index to be edited: ";
		bool compare = false;
		do {
			std::wcin >> selectedValue;
			ValueChecker::IfInt();
			if (!(std::find(availableValues.begin(), availableValues.end(), selectedValue) != availableValues.end())) {
				std::wcout << L"Value out of range. Please enter object index again: ";
			}
			else compare = true;
		} while (!(compare));
		std::advance(listIter, selectedValue - 1); //deletedValue - 1, because list indexes starts from 0, not 1
		ChangeSelectedValueInsideList(listIter);
		std::wcout << L"Done, file edited." << std::endl;
		changesNotSaved = true;
	}
	else std::wcout << L"File repository is empty. There is nothing do edit." << std::endl;
}

void::RepoManager::ChangeSelectedValueInsideList(std::list<RepoFile>::iterator inputIterator)
{
	std::wstring editedValue;
	std::getline(std::wcin, editedValue);
	std::wcout << L"Select edited value type: (1) System filename, (2) File description, (3) User defined filename, (4) file location" << std::endl;
	wchar_t selectedOption = '0';
	do
	{
		selectedOption = getch();
		switch (selectedOption)
		{
		case '1':
			inputIterator->SetSystemName(editedValue);
			break;
		case '2':
			inputIterator->SetFileDesc(editedValue);
			break;
		case '3':
			inputIterator->SetUserDefinedName(editedValue);
			break;
		case '4':
			inputIterator->SetFileLocation(editedValue);
			break;
		default:
			break;
		}
	} while (selectedOption != '0');
}