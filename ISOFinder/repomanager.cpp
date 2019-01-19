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

void RepoManager::DeleteFromRepo(RepoFile& inputRepoFile)
{
}

void RepoManager::ShowAllFiles()
{
	for (auto x : repoList)
	{
		std::wcout << x << std::endl;
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
	//std::list<RepoFile>::iterator repoIter = repoList.begin();
	//for (auto x : repoList)
	//{
	//	if (x.GetSystemName() == inputName)
	//	{
	//		std::wcout << x << std::endl;
	//	}
	//}
}

void RepoManager::DeleteFromRepoByDesc(std::wstring inputDesc)
{

	//std::list<RepoFile>::iterator repoIter = repoList.begin();
	//for (auto x : repoList)
	//{
	//	repoIter++;
	//	if (x.GetFileDesc() == inputDesc)
	//	{
	//		std::wcout << x << std::endl;
	//	}
	//}
}

void RepoManager::DeleteFromRepoByUserDefinedName(std::wstring inputUserDefinedName)
{
	//std::list<RepoFile>::iterator repoIter = repoList.begin();
	//for (auto x : repoList)
	//{
	//	if (x.GetUserDefinedName() == inputUserDefinedName)
	//	{
	//		std::wcout << x << std::endl;
	//	}
	//}
}

void RepoManager::DeleteFromRepoByLocation(std::wstring inputLocation)
{
	//std::list<RepoFile>::iterator repoIter = repoList.begin();
	//for (auto x : repoList)
	//{
	//	if (x.GetFileLocation() == inputLocation)
	//	{
	//		std::wcout << x << std::endl;
	//	}
	//}
}
